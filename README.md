# **Pradžia**

Testai daryti prieš milisekundžių keitimą į sekundes.

Įvestis buvo 5 1.000 5 10.000 5 100.000 5 1.000.000 5 10.000.000

| Komanda             | Ką daro                    |
| ------------------- | -------------------------- |
| 5                   | pasirinkimas failo kurimui |
| 1.000 - 10.000.000  | studentų kiekis faile      |

Kai programa baigia kurti failą, ji grįžta į meniu ciklą ir jei yra įvesti papildomi duomenys jis toliau kuria kitus failus.

Kuriant failus nustačiau, kad generuotu studentus su 7 namų darbų pažymiais, kad visi atlikti tyrimai su esamais 5 failais būtų patikimi. (Jog nebūtų tokio varianto, kad milijoninis failas su 15 ND uztrunka 200 sekundziu, o 10 milijoninis failas su 2 ND uztrunka 180 sekundziu.)


# **Tyrimas 1**

studList1000.txt "5 1000"

![image](https://github.com/user-attachments/assets/0379e0fb-b4f4-46be-9b84-69f850e1a2a2)

studList10000.txt "5 10000"

![image](https://github.com/user-attachments/assets/d295d2d5-2d0f-48f3-afe2-d6a1d2a56423)

studList100000.txt "5 100000"

![image](https://github.com/user-attachments/assets/2158c8bd-8f6c-4a79-a75d-596c83ab16e9)


studList1000000.txt "5 1000000"

![image](https://github.com/user-attachments/assets/099f422d-0226-436b-b592-8588d4cb7ca1)


studList10000000.txt "5 10000000"

![image](https://github.com/user-attachments/assets/91066151-082d-424f-8569-2d7e342e407c)

| Studentų kiekis   | Failo kūrimo laikas |
| ----------------- | ------------------- |
| Tūkstantis        | 20 ms               |
| Dešimt tūkstancių | 198 ms              |
| Šimtas tūkstancių | 1968 ms             |
| Milijonas         | 20028 ms            |
| Dešimt milijonų   | 196357 ms           |


# **Tyrimas 2**

Ivedu iskart “6 studList1000.txt 1 3”, nes programoje tenka laukti ivesties, ir tai dirbtiniu budu padidintu programos vykimo ilgi.

| Komanda           | Ką daro                                                |
| ----------------- | ------------------------------------------------------ |
| 6                 | failo surušiavimo pasirinkimas                         |
| studList1000.txt  | failo pavadinimas                                      |
| 1                 | pasirinkimas galutinį rezultatą skaičiuoti vidurkiu    |
| 6                 | pasirinkimas rušiuoti failus pagal galutinius pažymius |


studList1000.txt “6 studList1000.txt 1 3”

![image](https://github.com/user-attachments/assets/319d3088-fead-4e68-b01d-ff85715aba6a)

| Duomenų nuskaitymas  | Studentų rušiavimas | Failų išvedimas | Visa trukmė |
| -------------------- | ------------------- | --------------- | ----------- |
| 44 ms  | 0 ms  | 10 ms | 64 ms |


studList10000.txt “6 studList10000.txt 1 3”

![image](https://github.com/user-attachments/assets/8c2503bb-654c-4ecc-a814-62901722cf10)

| Duomenų nuskaitymas  | Studentų rušiavimas | Failų išvedimas | Visa trukmė |
| -------------------- | ------------------- | --------------- | ----------- |
| 382 ms  | 0 ms  | 41 ms | 519 ms |


studList100000.txt “6 studList100000.txt 1 3”

![image](https://github.com/user-attachments/assets/e26e502c-6bce-4b83-861b-aa0aa37045dc)

| Duomenų nuskaitymas  | Studentų rušiavimas | Failų išvedimas | Visa trukmė |
| -------------------- | ------------------- | --------------- | ----------- |
| 3.895 ms  | 0 ms  | 404 ms | 5.273 ms |


studList1000000.txt “6 studList1000000.txt 1 3”

![image](https://github.com/user-attachments/assets/345755ce-871b-4737-a4f2-1f628761cc0a)

| Duomenų nuskaitymas  | Studentų rušiavimas | Failų išvedimas | Visa trukmė |
| -------------------- | ------------------- | --------------- | ----------- |
| 38.946 ms  | 0 ms  | 4.175 ms | 51.235 ms |


studList10000000.txt “6 studList10000000.txt 1 3”

![image](https://github.com/user-attachments/assets/cb185b99-9566-4ab4-aea2-f0fbed3e5820)

| Duomenų nuskaitymas  | Studentų rušiavimas | Failų išvedimas | Visa trukmė |
| -------------------- | ------------------- | --------------- | ----------- |
| 388.998 ms  | 0 ms  | 42.907 ms | 516.780 ms |
