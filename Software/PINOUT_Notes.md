# Pinout Mapping
| GPIO | NET Name | Hooked To |
|------|----------|-----------|
| 0    | IT7      | J5 Pin 1  |
| 1    | OT1      | J1 Pin 7  |
| 2    | OT0      | J1 Pin 8  |
| 3    | OT3      | J1 Pin 5  |
| 4    | OIT4     | J6 Pin 4  |
| 5    | OIT5     | J6 Pin 3  |
| 6    | OIT6     | J6 Pin 2  |
| 7    | OIT7     | J6 Pin 1  |
| 8    | OIOT0    | J4 Pin 8  |
| 9    | OIOT1    | J4 Pin 7  |
| 10   | OIOT2    | J4 Pin 6  |
| 11   | OIOT3    | J4 Pin 5  |
| 12   | OIOT5    | J4 Pin 3  |
| 13   | OIOT4    | J4 Pin 4  |
| 14   | OIOT7    | J4 Pin 1  |
| 15   | OIOT6    | J4 Pin 2  |
| 16   | OOT1     | J2 Pin 7  |
| 17   | OOT0     | J2 Pin 8  |
| 18   | OOT3     | J2 Pin 5  |
| 19   | OOT2     | J2 Pin 6  |
| 20   | OOT5     | J2 Pin 3  |
| 21   | OIT3     | J6 Pin 5  |
| 22   | OIT2     | J6 Pin 6  |
| 23   | OIT1     | J6 Pin 7  |
| 24   | OIT0     | J6 Pin 8  |
| 25   | OOT4     | J2 Pin 4  |
| 26   | OOT7     | J2 Pin 1  |
| 27   | OOT6     | J2 Pin 2  |
| 28   | OT6      | J1 Pin 2  |
| 29   | OT7      | J1 Pin 1  |
| 30   | OT4      | J1 Pin 4  |
| 31   | OT5      | J1 Pin 3  |
| 32   | OT2      | J1 Pin 6  |
| 33   | IOT6     | J3 Pin 2  |
| 34   | IOT7     | J3 Pin 1  |
| 35   | IOT4     | J3 Pin 4  |
| 36   | IOT5     | J3 Pin 3  |
| 37   | IOT3     | J3 Pin 5  |
| 38   | IOT2     | J3 Pin 6  |
| 39   | IOT0     | J3 Pin 8  |
| 40   | IOT1     | J3 Pin 7  |
| 41   | IT6      | J5 Pin 2  |
| 42   | IT5      | J5 Pin 3  |
| 43   | IT4      | J5 Pin 4  |
| 44   | IT3      | J5 Pin 5  |
| 45   | IT2      | J5 Pin 6  |
| 46   | IT1      | J5 Pin 7  |
| 47   | IT0      | J5 Pin 8  |

## Headers
(Male Headers)
OT = J1
IOT = J3
IT = J5

(Female Headers)
OOT = J2
OIOT = J4
OIT = J6

### Male Header
                 ┌── PCB edge ──┐
Top view (component on top side, pins bent down):

 Row A  ○2  ○4  ○6  ○8  ○10 ○12
 Row B  ▣1  ○3  ○5  ○7  ○9  ○11

                 └──────────────┘

### Female Header

                 ┌── PCB Edge ──┐
Top view (receptacle on top side):

 Row A  ○12  ○10  ○8  ○6  ○4  ○2
 Row B  ○11  ○9   ○7  ○5  ○3  ▣1

                 └──────────────┘


### J1

| Pin | Row | Signal Name |
| --- | --- | ----------- |
| 1   | B   | OT7         |
| 2   | A   | OT6         |
| 3   | B   | OT5         |
| 4   | A   | OT4         |
| 5   | B   | OT3         |
| 6   | A   | OT2         |
| 7   | B   | OT1         |
| 8   | A   | OT0         |
| 9   | B   | GND         |
| 10  | A   | GND         |
| 11  | B   | 3V3         |
| 12  | A   | 3V3         |

### J2

| Pin | Row | Signal Name |
| --- | --- | ----------- |
| 1   | B   | OOT7        |
| 2   | A   | OOT6        |
| 3   | B   | OOT5        |
| 4   | A   | OOT4        |
| 5   | B   | OOT3        |
| 6   | A   | OOT2        |
| 7   | B   | OOT1        |
| 8   | A   | OOT0        |
| 9   | B   | GND         |
| 10  | A   | GND         |
| 11  | B   | 3V3         |
| 12  | A   | 3V3         |

### J3

| Pin | Row | Signal Name |
| --- | --- | ----------- |
| 1   | B   | IOT7        |
| 2   | A   | IOT6        |
| 3   | B   | IOT5        |
| 4   | A   | IOT4        |
| 5   | B   | IOT3        |
| 6   | A   | IOT2        |
| 7   | B   | IOT1        |
| 8   | A   | IOT0        |
| 9   | B   | GND         |
| 10  | A   | GND         |
| 11  | B   | 3V3         |
| 12  | A   | 3V3         |

### J4

| Pin | Row | Signal Name |
| --- | --- | ----------- |
| 1   | B   | OIOT7       |
| 2   | A   | OIOT6       |
| 3   | B   | OIOT5       |
| 4   | A   | OIOT4       |
| 5   | B   | OIOT3       |
| 6   | A   | OIOT2       |
| 7   | B   | OIOT1       |
| 8   | A   | OIOT0       |
| 9   | B   | GND         |
| 10  | A   | GND         |
| 11  | B   | 3V3         |
| 12  | A   | 3V3         |

### J5

| Pin | Row | Signal Name |
| --- | --- | ----------- |
| 1   | B   | IT7         |
| 2   | A   | IT6         |
| 3   | B   | IT5         |
| 4   | A   | IT4         |
| 5   | B   | IT3         |
| 6   | A   | IT2         |
| 7   | B   | IT1         |
| 8   | A   | IT0         |
| 9   | B   | GND         |
| 10  | A   | GND         |
| 11  | B   | 3V3         |
| 12  | A   | 3V3         |

### J6

| Pin | Row | Signal Name |
| --- | --- | ----------- |
| 1   | B   | OIT7        |
| 2   | A   | OIT6        |
| 3   | B   | OIT5        |
| 4   | A   | OIT4        |
| 5   | B   | OIT3        |
| 6   | A   | OIT2        |
| 7   | B   | OIT1        |
| 8   | A   | OIT0        |
| 9   | B   | GND         |
| 10  | A   | GND         |
| 11  | B   | 3V3         |
| 12  | A   | 3V3         |
