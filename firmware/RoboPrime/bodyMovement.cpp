/**
 * Part of RoboPrime Firmware.
 *
 * BodyMovement.cpp
 * Robot kinetics.
 * 
 * RoboPrime Firmware, (https://github.com/simonepri/RoboPrime)
 * Copyright (c) 2015, Simone Primarosa, (https://simoneprimarosa.com)
 *
 * Licensed under The MIT License
 * Redistribution of file must retain the above copyright notice.
 * 
 * @copyright     Copyright (c) 2015, Simone Primarosa, (https://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/RoboPrime)
 * @since         0.0.0
 * @require       SerialServo
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include "Arduino.h"
#include "serialServo.h"

#include "bodyMovement.h"

/**
 * pos array is located in FLASH momery and store information about the minimum,
 * and maximum angle avaible for a bodypart. It also store the default position
 * for each bodypart.
 */
body_pos_t
  BodyMovement::pos[HF_NUM][POS_SIZE] = SERVO_ANGLE_POS;

/**
 * offset array is located in FLASH momery and store information about the
 * angle offset for each bodypart in order to get all part alligned in case of
 * errors due to 3D printed pieces.
 */
body_offset_t
  BodyMovement::offset[HF_NUM][HF_SIZE] = SERVO_ANGLE_OFFSET;

/**
 * head and tail array is located in SRAM momery and store respectivley
 * information about the index of next free queue block and the index of the
 * last unfree block.
 */
uint8_t
  BodyMovement::head[HF_SIZE][HF_NUM],
  BodyMovement::tail[HF_SIZE][HF_NUM];

/**
 * queue array is located in SRAM momery and store information about the next
 * planned movment for each bodypart.
 */
block_t
  BodyMovement::queue[HF_SIZE][HF_NUM][BF_SIZE];

/**
 * Initializes class's fields.
 */
void BodyMovement::begin() {
  setDefault();
  
  for(uint8_t _idx = 0; _idx < HF_NUM; _idx++) {
    head[HF_R][_idx] = head[HF_L][_idx] = 0;
  }
}

/**
 * Checks if valid index is passed.
 *
 * @param _idx body part index.
 * @return true if the queue is empty, false otherwise.
 */
inline bool BodyMovement::isValidBodypart(uint8_t _idx) {
  return (_idx < HF_NUM);
}


/**
 * Applies a movment for a bodypart.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @param _angle angle*10 to set.
 */
void BodyMovement::setPos(bool _half, uint8_t _idx, uint16_t _angle) {
  if(!isValidBodypart(_idx)) {
    return;
  }
  raw_setPos(_half, _idx, _angle);
}

/**
 * Applies a sweep movement for a bodypart.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @param _angle angle*10 to set.
 * @param _time duration of
 * movment.
 */
void BodyMovement::setSweep(bool _half, uint8_t _idx, uint16_t _angle,
                            uint16_t _time) {
  if(!isValidBodypart(_idx)) {
    return;
  }
  _angle = raw_validAngle(_half, _idx, _angle);
  raw_setSweep(_half, _idx, _angle, _time);
}

/**
 * Sets all bodypart to their default position.
 */
void BodyMovement::setDefault() {
  uint16_t _deg;
  bool _half;
  for(uint8_t _idx = 0; _idx < HF_NUM; _idx++) {
    _deg = raw_getDefaultPos(_idx);
    _half = HF_R;
    raw_setPos(_half, _idx, _deg);
    _half = HF_L;
    raw_setPos(_half, _idx, _deg);
  }
}

/**
 * Sets the servo to the default position.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 */
void BodyMovement::setDefault(bool _half, uint8_t _idx) {
  if(!isValidBodypart(_idx)) {
    return;
  }
  uint16_t _deg = raw_getDefaultPos(_idx);
  raw_setPos(_half, _idx, _deg);
}

/**
 * Sets sequence mode status.
 *
 * @param _status true to enable false to disable.
 */
void BodyMovement::setSequence(bool _status) {
  if(_status) {
    SerialServo::enableSequence();
    return;
  }
  SerialServo::disableSequence();
}

/**
 * Keeps a bodypart in his position for some time.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @param _time duration of the movment.
 */
void BodyMovement::setWait(bool _half, uint8_t _idx, uint16_t _time) {
  if(!isValidBodypart(_idx)) {
    return;
  }
  raw_setWait(_half, _idx, _time);
}

/**
 * Gets the actual position of a bodypart.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @return channel angle.
 */
uint16_t BodyMovement::getPos(bool _half, uint8_t _idx) {
  if(!isValidBodypart(_idx)) {
    return 0;
  }
  return raw_getPos(_half, _idx);
}

/**
 * Gets the minimum position for a bodypart.
 *
 * @param _idx body part index.
 * @return channel angle.
 */
uint16_t BodyMovement::getMinPos(uint8_t _idx) {
  if(!isValidBodypart(_idx)) {
    return 0;
  }
  return raw_getMinPos(_idx);
}

/**
 * Gets the default position for a bodypart.
 *
 * @param _idx body part index.
 * @return channel angle.
 */
uint16_t BodyMovement::getDefaultPos(uint8_t _idx) {
  if(!isValidBodypart(_idx)) {
    return 0;
  }
  return raw_getDefaultPos(_idx);
}

/**
 * Gets the maximum position for a bodypart.
 *
 * @param _idx body part index.
 * @return channel angle.
 */
uint16_t BodyMovement::getMaxPos(uint8_t _idx) {
  if(!isValidBodypart(_idx)) {
    return 0;
  }
  return raw_getMaxPos(_idx);
}

/**
 * Checks if a bodypart is moving
 *
 * @param right or left body part, body part index.
 * @return true if the bodyport is moving.
 */
bool BodyMovement::isMoving(bool _half, uint8_t _idx) {
  if(!isValidBodypart(_idx)) {
    return false;
  }
  return raw_isMoving(_half, _idx);
}

/**
 * Inserts a movement into the queue.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @param _angle angle*10 to set.
 * @param _time duration of the movment.
 * 
 * @return false if the queue is full or the bodypart is invalid.
 */
bool BodyMovement::pushQueue(bool _half, uint8_t _idx, uint16_t _angle,
                             uint16_t _time) {
  if(!isValidBodypart(_idx) || raw_isQueueFull(_half, _idx)) {
    return false;
  }
  raw_pushQueue(_half, _idx, _angle, _time);
  return true;
}

/**
 * Executes one movement from the queue.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @return false if the queue is empty or the bodypart is invalid.
 */
bool BodyMovement::popQueue(bool _half, uint8_t _idx) {
  if(!isValidBodypart(_idx) || isQueueEmpty(_half, _idx)) {
    return false;
  }
  raw_popQueue(_half, _idx);
  return true;
}

/**
 * Checks if the queue is full.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @return true if the queue is full, false otherwise.
 */
bool BodyMovement::isQueueFull(bool _half, uint8_t _idx) {
  if(!isValidBodypart(_idx)) {
    return true;
  }
  return raw_isQueueFull(_half, _idx);
}

/**
 * Checks if the queue is empty.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @return true if the queue is empty, false otherwise.
 */
bool BodyMovement::isQueueEmpty(bool _half, uint8_t _idx) {
  if(!isValidBodypart(_idx)) {
    return false;
  }
  return raw_isQueueEmpty(_half, _idx);
}

/**
 * Contrains the angle into his bounds.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @param _angle angle*10 to set.
 * @return costrain angle.
 */
inline uint16_t BodyMovement::raw_validAngle(const bool &_half,
                                             const uint8_t &_idx,
                                             const uint16_t &_angle) {
  uint16_t _min = raw_getMinPos(_idx);
  uint16_t _max = raw_getMaxPos(_idx);
  int8_t _offset = pgm_read_word_near(&(offset[_idx][_half]));
  if(_angle < _min) {
    if(_offset > 0) {
      return _min + _offset;
    }
    return _min;
  }
  if(_angle > _max) {
    if(_offset < 0) {
      return _max + _offset;
    }
    return _max;
  }
  if(_offset > 0) {
    if(_angle + _offset > _max) {
      return _max;
    }
  }
  else {
    if(-_offset > _angle) {
      return _min;
    }
    if(_angle + _offset < _min) {
      return _min;
    }
  }
  return _angle + _offset;
}

/**
 * See setPos.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @param _angle angle*10 to set.
 */
inline void BodyMovement::raw_setPos(const bool &_half, const uint8_t &_idx,
                                     const uint16_t &_angle) {
  uint16_t _anglefix = raw_validAngle(_half, _idx, _angle);
  if(_half) {
    SerialServo::writeAngle(HF_NUM + _idx, _anglefix, _half);
    return;
  }
  SerialServo::writeAngle(_idx, _anglefix);
}

/**
 * See setSweep.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @param _angle angle*10 to set.
 * @param _time duration of the movment.
 */
inline void BodyMovement::raw_setSweep(const bool &_half, const uint8_t &_idx,
                                       const uint16_t &_angle,
                                       const uint16_t &_time) {
  if(_half) {
    SerialServo::sweepAngle(HF_NUM + _idx, _angle, _time, _half);
    return;
  }
  SerialServo::sweepAngle(_idx, _angle, _time);
}

/**
 * See setDefault.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 */
inline void BodyMovement::raw_setDefault(const bool &_half,
                                         const uint8_t &_idx) {
  raw_setPos(_half, _idx, raw_getDefaultPos(_idx));
}

/**
 * See setWait.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @param _time duration of the movment.
 */
inline void BodyMovement::raw_setWait(const bool &_half, const uint8_t &_idx,
                                      const uint16_t &_time) {
  if(_half) {
    SerialServo::wait(HF_NUM + _idx, _time);
    return;
  }
  SerialServo::wait(_idx, _time);
}

/**
 * See getPos
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @return channel angle.
 */
inline uint16_t BodyMovement::raw_getPos(const bool &_half,
                                         const uint8_t &_idx) {
  if(_half) {
    return SerialServo::readAngle(HF_NUM + _idx, _half);
  }
  return SerialServo::readAngle(_idx);
}

/**
 * See getMinPos
 *
 * @param _idx body part index.
 * @return channel angle.
 */
inline uint16_t BodyMovement::raw_getMinPos(const uint8_t &_idx) {
  return pgm_read_word_near(&(pos[_idx][POS_MIN]));
}

/**
 * See getDefaultPos
 *
 * @param _idx body part index.
 * @return channel angle.
 */
inline uint16_t BodyMovement::raw_getDefaultPos(const uint8_t &_idx) {
  return pgm_read_word_near(&(pos[_idx][POS_MED]));
}

/**
 * See getMaxPos
 *
 * @param _idx body part index.
 * @return channel angle.
 */
inline uint16_t BodyMovement::raw_getMaxPos(const uint8_t &_idx) {
  return pgm_read_word_near(&(pos[_idx][POS_MAX]));
}

/**
 * See isMoving
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @return true if the bodyport is moving.
 */
inline bool BodyMovement::raw_isMoving(const bool &_half, const uint8_t &_idx) {
  if(_half) {
    return SerialServo::isMoving(HF_NUM + _idx);
  }
  return SerialServo::isMoving(_idx);
}
 
/**
 * See pushQueue.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @param _angle angle*10 to set.
 * @param _time duration of the movment.
 */
inline void BodyMovement::raw_pushQueue(const bool &_half, const uint8_t &_idx,
                                        const uint16_t &_angle,
                                        const uint16_t &_time) {
  queue[_half][_idx][head[_half][_idx]].movAngle = _angle;
  queue[_half][_idx][head[_half][_idx]].movTime = _time;
  head[_half][_idx] = nextQueue(head[_half][_idx]);
}

/**
 *  See popQueue.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 */
inline void BodyMovement::raw_popQueue(const bool &_half, const uint8_t &_idx) {
  if(queue[_half][_idx][tail[_half][_idx]].movAngle == INVALID_BODY_POS) {
    raw_setWait(_half, _idx, queue[_half][_idx][tail[_half][_idx]].movTime);
  }
  else {
    raw_setSweep(_half, _idx, queue[_half][_idx][tail[_half][_idx]].movAngle, 
                 queue[_half][_idx][tail[_half][_idx]].movTime);
  }
  tail[_half][_idx] = nextQueue(tail[_half][_idx]);
}

/**
 * See isQueueFull.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @return true if the queue is full, false otherwise.
 */
inline bool BodyMovement::raw_isQueueFull(const bool &_half,
                                          const uint8_t &_idx) {
  return fullQueue(nextQueue(head[_half][_idx]), tail[_half][_idx]);
}

/**
 * See isQueueEmpty.
 *
 * @param _half right or left body part.
 * @param _idx body part index.
 * @return true if the queue is empty, false otherwise.
 */
inline bool BodyMovement::raw_isQueueEmpty(const bool &_half,
                                           const uint8_t &_idx) {
  return emptyQueue(head[_half][_idx], tail[_half][_idx]);
}

/**
 * This routine is called by the loop and flush the movement queue.
 */
void BodyMovement::movementPlanner() {
  static uint8_t _idx = 0;
  bool _half = false;
  do {
    if(!isMoving(_half, _idx) && !raw_isQueueEmpty(_half, _idx)) {
      raw_popQueue(_half, _idx);
    }
    _half = !_half;
  }
  while(_half);
  if(++_idx >= HF_NUM) {
    _idx = 0;
  }
}
