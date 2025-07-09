# Pinout Mapping
| GPIO | NET Name | Hooked To |
|------|----------|-----------|
| 0    | IT7      | unknown   |
| 1    | OT1      | unknown   |
| 2    | OT0      | unknown   |
| 3    | OT3      | unknown   |
| 4    | OIT4     | unknown   |
| 5    | OIT5     | unknown   |
| 6    | OIT6     | unknown   |
| 7    | OIT7     | unknown   |
| 8    | OIOT0    | unknown   |
| 9    | OIOT1    | unknown   |
| 10   | OIOT2    | unknown   |
| 11   | OIOT3    | unknown   |
| 12   | OIOT5    | unknown   |
| 13   | OIOT4    | unknown   |
| 14   | OIOT7    | unknown   |
| 15   | OIOT6    | unknown   |
| 16   | OOT1     | unknown   |
| 17   | OOT0     | unknown   |
| 18   | OOT3     | unknown   |
| 19   | OOT2     | unknown   |
| 20   | OOT5     | unknown   |
| 21   | OIT3     | unknown   |
| 22   | OIT2     | unknown   |
| 23   | OIT1     | unknown   |
| 24   | OIT0     | unknown   |
| 25   | OOT4     | unknown   |
| 26   | OOT7     | unknown   |
| 27   | OOT6     | unknown   |
| 28   | OT6      | unknown   |
| 29   | OT7      | unknown   |
| 30   | OT4      | unknown   |
| 31   | OT5      | unknown   |
| 32   | OT2      | unknown   |
| 33   | IOT6     | unknown   |
| 34   | IOT7     | unknown   |
| 35   | IOT4     | unknown   |
| 36   | IOT5     | unknown   |
| 37   | IOT3     | unknown   |
| 38   | IOT2     | unknown   |
| 39   | IOT0     | unknown   |
| 40   | IOT1     | unknown   |
| 41   | IT6      | unknown   |
| 42   | IT5      | unknown   |
| 43   | IT4      | unknown   |
| 44   | IT3      | unknown   |
| 45   | IT2      | unknown   |
| 46   | IT1      | unknown   |
| 47   | IT0      | unknown   |

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
