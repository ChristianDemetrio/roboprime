# RoboPrime 🤖 [![License](https://img.shields.io/aur/license/yaourt.svg)](https://github.com/simonepri/roboprime/)
> Full featured 21 DOF 3D Printed Humanoid Robot based on ATmega328P chip
<p align="center">
  <img src="gallery/hello-world.gif" alt="RoboPrime Hello">
</p>
Description coming soon.

### Press
The project has been featured here:
<p>
  <a href="http://explore.makerfairerome.eu/poi/Exhibit_1447" target="_blank"><img src="https://user-images.githubusercontent.com/3505087/27860797-617e0b1a-617e-11e7-9bb1-460a81c064e9.png" alt="Maker Faire" height="50"></a>
  <a href="http://www.ilmessaggero.it/pay/edicola/maker_faire_roma_14_ottobre-2001501.html" target="_blank"> <img src="https://user-images.githubusercontent.com/3505087/27860876-c14fec8e-617e-11e7-8f0e-690555bec853.png" alt="Il Messagero" height="50"></a>
</p>

### Gallery
Some images done during the development process:

<p>
  <img src="gallery/roboprime-v2.jpg" alt="RoboPrime" height="128">
  <img src="gallery/roboprime-v2-front.jpg" alt="RoboPrime" height="128">
  <img src="gallery/roboprime-v2-leg.jpg" alt="RoboPrime" height="128">
  <img src="gallery/roboprime-v2-assembling.jpg" alt="RoboPrime" height="128">
  <img src="gallery/roboprime-v2-printing.jpg" alt="RoboPrime" height="128">
  <img src="gallery/roboprime-v1-front.jpg" alt="RoboPrime" height="128">
  <img src="gallery/roboprime-v1-weigth.jpg" alt="RoboPrime" height="128">
  <img src="gallery/roboprime-v1-top.jpg" alt="RoboPrime" height="128">
  <img src="gallery/board-back.jpg" alt="RoboPrime" height="128">
  <img src="gallery/board-front.jpg" alt="RoboPrime" height="128">
  <img src="gallery/hello-animation.gif" alt="RoboPrime" height="128">
  <img src="gallery/fuckoff-animation.gif" alt="RoboPrime" height="128">
  <img src="gallery/sitdown-animation.gif" alt="RoboPrime" height="128">
  <img src="gallery/walk-animation.gif" alt="RoboPrime" height="128">
</p>

> Click on the image to enlarge.

## Getting Started

### Hardware
The total cost is about $60-$100. Depending on where you buy the pieces.

Amount | Part
-------|---------
1 | Arduino Pro Micro (Atmega328p)
1 | HC-05 (Bluetooth)
2 | 74HC4017 (5-stage Johnson decade counter)
1 | MPU-6050 (Gyroscope + Accellerometer UNUSED)
21 | MG90S 9G (Servo motors)
2 | 5A DC-DC (Voltage step-down Used to power the servos)
1 | Ad-hoc board (See wiring section)

### Screws
Screws are used to join pieces together.

The total cost is about $15.

Amount | Size
-------|------
37 | M2 x 4mm
32 | M2 x 14mm
19 | M2 x 20mm

### 3D Models
You need to print it in ABS, since servos becomes hot after a while and can melt the plastic.

The printing cost is about $20-$30.

> SX_* models needs to be mirrored on the correct axis before the printing process.

Part | Amount | Download
-----|--------|---------
<img src="3D/stl/thumb/38xSP_Cover_1_foro.png" alt="SP_Cover_1_foro" width="50" height="50"> | 38 | [SP_Cover_1_foro](3D/stl/38xSP_Cover_1_foro.stl)
<img src="3D/stl/thumb/1xMID_Scapole.png" alt="MID_Scapole" width="50" height="50"> | 1 | [MID_Scapole](3D/stl/1xMID_Scapole.stl)
<img src="3D/stl/thumb/1xMID_Torace.png" alt="MID_Torace" width="50" height="50"> | 1 | [MID_Torace](3D/stl/1xMID_Torace.stl)
<img src="3D/stl/thumb/1xMID_Anca_TOP.png" alt="MID_Anca_TOP" width="50" height="50"> | 1 | [MID_Anca_TOP](3D/stl/1xMID_Anca_TOP.stl)
<img src="3D/stl/thumb/2xMID_Anca_BTM.png" alt="MID_Anca_BTM" width="50" height="50"> | 2 | [MID_Anca_BTM](3D/stl/2xMID_Anca_BTM.stl)
<img src="3D/stl/thumb/1xDX_Spalla_A.png" alt="DX_Spalla_A" width="50" height="50"> | 1 | [DX_Spalla_A](3D/stl/1xDX_Spalla_A.stl)
<img src="3D/stl/thumb/1xDX_Spalla_B.png" alt="DX_Spalla_B" width="50" height="50"> | 1 | [DX_Spalla_B](3D/stl/1xDX_Spalla_B.stl)
<img src="3D/stl/thumb/1xDX_Avambraccio_A.png" alt="DX_Avambraccio_A" width="50" height="50"> | 1 | [DX_Avambraccio_A](3D/stl/1xDX_Avambraccio_A.stl)
<img src="3D/stl/thumb/1xDX_Avambraccio_B.png" alt="DX_Avambraccio_B" width="50" height="50"> | 1 | [DX_Avambraccio_B](3D/stl/1xDX_Avambraccio_B.stl)
<img src="3D/stl/thumb/1xDX_Gomito_A.png" alt="DX_Gomito_A" width="50" height="50"> | 1 | [DX_Gomito_A](3D/stl/1xDX_Gomito_A.stl)
<img src="3D/stl/thumb/1xDX_Gomito_B.png" alt="DX_Gomito_B" width="50" height="50"> | 1 | [DX_Gomito_B](3D/stl/1xDX_Gomito_B.stl)
<img src="3D/stl/thumb/1xDX_Braccio.png" alt="DX_Braccio" width="50" height="50"> | 1 | [DX_Braccio](3D/stl/1xDX_Braccio.stl)
<img src="3D/stl/thumb/1xDX_Anca_A.png" alt="DX_Anca_A" width="50" height="50"> | 1 | [DX_Anca_A](3D/stl/1xDX_Anca_A.stl)
<img src="3D/stl/thumb/1xDX_Anca_B.png" alt="DX_Anca_B" width="50" height="50"> | 1 | [DX_Anca_B](3D/stl/1xDX_Anca_B.stl)
<img src="3D/stl/thumb/1xDX_Inguine_A.png" alt="DX_Inguine_A" width="50" height="50"> | 1 | [DX_Inguine_A](3D/stl/1xDX_Inguine_A.stl)
<img src="3D/stl/thumb/1xDX_Inguine_B.png" alt="DX_Inguine_B" width="50" height="50"> | 1 | [DX_Inguine_B](3D/stl/1xDX_Inguine_B.stl)
<img src="3D/stl/thumb/1xDX_Ginocchio_A.png" alt="DX_Ginocchio_A" width="50" height="50"> | 1 | [DX_Ginocchio_A](3D/stl/1xDX_Ginocchio_A.stl)
<img src="3D/stl/thumb/1xDX_Ginocchio_B.png" alt="DX_Ginocchio_B" width="50" height="50"> | 1 | [DX_Ginocchio_B](3D/stl/1xDX_Ginocchio_B.stl)
<img src="3D/stl/thumb/1xDX_Gamba_A.png" alt="DX_Gamba_A" width="50" height="50"> | 1 | [DX_Gamba_A](3D/stl/1xDX_Gamba_A.stl)
<img src="3D/stl/thumb/1xDX_Gamba_B.png" alt="DX_Gamba_B" width="50" height="50"> | 1 | [DX_Gamba_B](3D/stl/1xDX_Gamba_B.stl)
<img src="3D/stl/thumb/1xDX_Caviglia_A.png" alt="DX_Caviglia_A" width="50" height="50"> | 1 | [DX_Caviglia_A](3D/stl/1xDX_Caviglia_A.stl)
<img src="3D/stl/thumb/1xDX_Caviglia_B.png" alt="DX_Caviglia_B" width="50" height="50"> | 1 | [DX_Caviglia_B](3D/stl/1xDX_Caviglia_B.stl)
<img src="3D/stl/thumb/1xDX_Piede_A.png" alt="DX_Piede_A" width="50" height="50"> | 1 | [DX_Piede_A](3D/stl/1xDX_Piede_A.stl)
<img src="3D/stl/thumb/1xDX_Piede_B.png" alt="DX_Piede_B" width="50" height="50"> | 1 | [DX_Piede_B](3D/stl/1xDX_Piede_B.stl)
<img src="3D/stl/thumb/1xDX_Spalla_A.png" alt="SX_Spalla_A" width="50" height="50"> | 1 | [SX_Spalla_A](3D/stl/1xDX_Spalla_A.stl)
<img src="3D/stl/thumb/1xDX_Spalla_B.png" alt="SX_Spalla_B" width="50" height="50"> | 1 | [SX_Spalla_B](3D/stl/1xDX_Spalla_B.stl)
<img src="3D/stl/thumb/1xDX_Avambraccio_A.png" alt="SX_Avambraccio_A" width="50" height="50"> | 1 | [SX_Avambraccio_A](3D/stl/1xDX_Avambraccio_A.stl)
<img src="3D/stl/thumb/1xDX_Avambraccio_B.png" alt="SX_Avambraccio_B" width="50" height="50"> | 1 | [SX_Avambraccio_B](3D/stl/1xDX_Avambraccio_B.stl)
<img src="3D/stl/thumb/1xDX_Gomito_A.png" alt="SX_Gomito_A" width="50" height="50"> | 1 | [SX_Gomito_A](3D/stl/1xDX_Gomito_A.stl)
<img src="3D/stl/thumb/1xDX_Gomito_B.png" alt="SX_Gomito_B" width="50" height="50"> | 1 | [SX_Gomito_B](3D/stl/1xDX_Gomito_B.stl)
<img src="3D/stl/thumb/1xDX_Braccio.png" alt="SX_Braccio" width="50" height="50"> | 1 | [SX_Braccio](3D/stl/1xDX_Braccio.stl)
<img src="3D/stl/thumb/1xDX_Anca_A.png" alt="SX_Anca_A" width="50" height="50"> | 1 | [SX_Anca_A](3D/stl/1xDX_Anca_A.stl)
<img src="3D/stl/thumb/1xDX_Anca_B.png" alt="SX_Anca_B" width="50" height="50"> | 1 | [SX_Anca_B](3D/stl/1xDX_Anca_B.stl)
<img src="3D/stl/thumb/1xDX_Inguine_A.png" alt="SX_Inguine_A" width="50" height="50"> | 1 | [SX_Inguine_A](3D/stl/1xDX_Inguine_A.stl)
<img src="3D/stl/thumb/1xDX_Inguine_B.png" alt="SX_Inguine_B" width="50" height="50"> | 1 | [SX_Inguine_B](3D/stl/1xDX_Inguine_B.stl)
<img src="3D/stl/thumb/1xDX_Ginocchio_A.png" alt="SX_Ginocchio_A" width="50" height="50"> | 1 | [SX_Ginocchio_A](3D/stl/1xDX_Ginocchio_A.stl)
<img src="3D/stl/thumb/1xDX_Ginocchio_B.png" alt="SX_Ginocchio_B" width="50" height="50"> | 1 | [SX_Ginocchio_B](3D/stl/1xDX_Ginocchio_B.stl)
<img src="3D/stl/thumb/1xDX_Gamba_A.png" alt="SX_Gamba_A" width="50" height="50"> | 1 | [SX_Gamba_A](3D/stl/1xDX_Gamba_A.stl)
<img src="3D/stl/thumb/1xDX_Gamba_B.png" alt="SX_Gamba_B" width="50" height="50"> | 1 | [SX_Gamba_B](3D/stl/1xDX_Gamba_B.stl)
<img src="3D/stl/thumb/1xDX_Caviglia_A.png" alt="SX_Caviglia_A" width="50" height="50"> | 1 | [SX_Caviglia_A](3D/stl/1xDX_Caviglia_A.stl)
<img src="3D/stl/thumb/1xDX_Caviglia_B.png" alt="SX_Caviglia_B" width="50" height="50"> | 1 | [SX_Caviglia_B](3D/stl/1xDX_Caviglia_B.stl)
<img src="3D/stl/thumb/1xDX_Piede_A.png" alt="SX_Piede_A" width="50" height="50"> | 1 | [SX_Piede_A](3D/stl/1xDX_Piede_A.stl)
<img src="3D/stl/thumb/1xDX_Piede_B.png" alt="SX_Piede_B" width="50" height="50"> | 1 | [SX_Piede_B](3D/stl/1xDX_Piede_B.stl)

### Wiring
Schematics are contained in the `schematics` folder.
<img src="https://user-images.githubusercontent.com/3505087/27921374-e55e0990-6277-11e7-978f-4e2bca6f3ce1.png" alt="RoboPrime fritzing" width="500">

### Firmware
The firmware is contained in the `firmware` folder and can be compiled and uploaded to the board thanks to the Arduino IDE.

<img src="https://user-images.githubusercontent.com/3505087/27862900-dbcd7a6e-6187-11e7-95c3-12126a2519e5.png" alt="Firmware size" width="720">

## Usage

### Commands
The firmware allows you to fully control the robot through bluetooth in order to make complex things.
Those are the commands implemented that can be sended through the serial protocol.

Name | Syntax | Parameters | Description
-----|--------|------------|------------
S0 | `S0 Ri`<br>or<br>`S0 Li` | **i** = index[0-9] (optional) | Move a servo to its default position.<br>If no index is passed all servos will be reset.
S1 | `S1 Ri Ad`<br>or<br>`S1 Li Ad` | **i** = index[0-9]<br>**d** = angle[0-1800] | Move a servo to a specific angle.<br>The value 0 corresponds to 0° and <br>the value 1800 corresponds to 180°.
S2 | `S1 Ri Ad Tm`<br>or<br>`S1 Li Ad Tm` | **i** = index[0-9]<br>**d** = angle[0-1800]<br>**m** = duration[ms] | Move a servo to a specific angle gradually by <br>sweeping it for a specific amount of time.
S3 | `S3 An Ds Tm` | **n** = anim idx[0-10]<br>**s** = space[cm]<br>**m** = duration[ms] | Apply a specific animation.<br>`space` and `duration` are unused at the moment <br>but are supposed to be used as parameters for <br>certain animations. See animations section for <br>the list of animations available.
Q0 | `Q0 Ri Ad`<br>or<br>`Q0 Ri Ad` | **i** = index[0-9]<br>**d** = angle[0-1800] | Similar to `S1`, but the movement is added to <br>the movements queue. If the angle value is 0 <br>a pause will be planned instead.<br>(A pause will make the next planned <br>movement, on the same motor index, hang until <br>the pause is not ended)<br>This is used in order to plan complex <br>synchronized movements. (E.g. Animations)
C0 | `Ri Wp`<br>or<br>`Li Wp` | **i** = index[0-9]<br>**p** = pulse width[us] | Sets a specific pulse width to a specific <br>motor for calibration purposes.

### Animations

The firmware contains some basic animations hardcoded inside it:

Id | Name | Status
---|------|-------
0  | Forward walk.                         | WIP
1  | Backward walk.                        | NO
2  | Side walk to right.                   | NO
3  | Side walk to left.                    | NO
4  | Clockwise standstill rotation.        | NO
5  | Counterclockwise standstill rotation. | NO
6  | Clockwise curved walk.                | NO
7  | Counterclockwise curved walk.         | NO
8  | Sit down.                             | DONE
9  | Hello.                                | DONE
10 | Fuck off.                             | DONE

## Project Analysis
This document was written for my high-school exam in order to give to the professors some basic knowledge to make them understand how the project works.

Unfortunately it's written in Italian 🇮🇹

[The document is available here](https://goo.gl/ZiD9bK)

## Authors
* **Simone Primarosa** - [simonepri](https://github.com/simonepri)

See also the list of [contributors](https://github.com/simonepri/roboprime/contributors) who participated in this project.

## License
This project is licensed under the GPL-3.0 License - see the [LICENSE](LICENSE) file for details.
