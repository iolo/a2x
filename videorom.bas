10 FOR V = 0 TO 15
20 FOR H = 0 TO 15
30 C = V * 16 + H
40 A = 1024 + (V - INT(V / 8) * 8) * 128 + 40 * INT(V / 8) + H
50 POKE A, C
60 NEXT H
70 NEXT V
