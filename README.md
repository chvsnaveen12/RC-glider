# RC-glider
Created Transmitter and Receiver pair for a lightweight powered RC glider. 
This is a slightly modified version of the Tx and RX found (here.)[https://www.youtube.com/watch?v=9SMyBN-B3Vo]

More images [here.](https://photos.app.goo.gl/gMJk42ySzAyyzqAx9)

## The changes
Removed the YAW channel from the transmitter.
Only have 1 servo channel.
Mixing for differential Yaw control.

## Wiring Tx
The wiring for the transmitter remained entirely the same, except I didn't bother to connect the Yaw potentiometer.

## Wiring Rx
| Arduino Pin | Connection  |
| :--------   | :-------    |
|   d5        | Motor1      |
|   d6        | Motor2      |
|   d7        | Pitch Servo |

Connections to Motor1 and Motor2 are through IRLZ44N power MOSFETS.

The NRF24L01 is connected in the original way.

## Image

![image](https://user-images.githubusercontent.com/90030628/196432373-cfe84476-e6af-4503-9e92-a232af86ec83.png)
