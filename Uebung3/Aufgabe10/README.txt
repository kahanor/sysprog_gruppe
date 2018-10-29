Aufgabe 10)

1)
Zeile 5,25&27: string.h Bibliothek wurde nicht importiert in der
die Funktionen "strlen" und "strcmp" sind

2)
Zeile 8: die Strings beginnen beim Index 0. Daher muss beim 
"Rückwärtslesen" von st1 beim Index st1_len -1 begonnen werden
und nicht bei st1_len

3)
Zeile 14: 'exit' ist ein character und kein String und wird jedoch
einem char-Pointer zugewiesen

4)
Zeile 16&17: es werden pro char-Pointer 100 Bytes Speicher allokiert
und kein Speicherplatz für 100 chars

5)
Zeile 22: scanf hört bei Whitespaces auf zu lesen und achtet 
darüberhinaus nicht auf die Kapazität der char-Pointer

6)
Zeile 30: beim Erstellen des zweiten String str2 wird kein
terminierendes '\0' am Ende hinzugefügt

7)
Zeile 36: Zwei Strings werden mit '==' verglichen anstatt mit
strcmp

8)
Zeile 36: st1 muss nicht vollständig in Großbuchstaben
geschrieben sein. Da st2 komplett aus Großbuchstaben besteht,
werden die Strings trotz Gleichheit als ungleich bewertet

9)
der Speicher der char-Pointer st1 und st2 muss beim Beenden 
des Programms freigegeben werden


 