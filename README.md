Pradžia
Testai daryti prieš milisekundžių keitimą į sekundes.
Įvestis buvo 5 1000 5 10000 5 100000 5 1000000 5 10000000
(5 - pasirinkimas sukurti failą, antras skaičius yra studentų kiekis faile)
Kai programa baigia kurti failą, tai grižtama atgal į meniu ciklą ir del toliau ivestų duomenų jis toliau kuria kitus failus.
Kuriant failus nustačiau, kad generuotu studentus su 7 namų darbų pažymiais, kad visi atlikti tyrimai su esamais 5 failais būtų patikimi.(Jog nebūtų tokio varianto, kad milijoninis failas su 15 ND uztrunka 200 sekundziu, o 10 milijoninis failas su 2 ND uztrunka 180 sekundziu.)

Tyrimas 1
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



Tyrimas 2
Ivedu iskart “6 studList1000.txt 1 3”, nes programoje tenka laukti ivesties, ir tai dirbtiniu budu padidintu programos vykimo ilgi.
6 – pasirinkimas failo surusiavimo
1 – pasirinkimas galutini rezultata skaiciuoti vidurkiu
3 – pasirinkimas rusiuoti galutinius sukurtus failus galutiniu pazymiu

studList1000.txt “6 studList1000.txt 1 3”

![image](https://github.com/user-attachments/assets/319d3088-fead-4e68-b01d-ff85715aba6a)

Duomenu nuskaitymas: 44 ms
Studentu rusiavimas: 0 ms
Failu isvedimas: 10 ms
Visa trukme: 64 ms


studList10000.txt “6 studList10000.txt 1 3”

![image](https://github.com/user-attachments/assets/8c2503bb-654c-4ecc-a814-62901722cf10)

Duomenu nuskaitymas: 382 ms
Studentu rusiavimas: 0 ms
Failu isvedimas: 41 ms
Visa trukme: 519 ms


studList100000.txt “6 studList100000.txt 1 3”

![image](https://github.com/user-attachments/assets/e26e502c-6bce-4b83-861b-aa0aa37045dc)

Duomenu nuskaitymas: 3895 ms
Studentu rusiavimas: 0 ms
Failu isvedimas:  404 ms
Visa trukme:  5273 ms


studList1000000.txt “6 studList1000000.txt 1 3”

![image](https://github.com/user-attachments/assets/345755ce-871b-4737-a4f2-1f628761cc0a)

Duomenu nuskaitymas: 38946 ms
Studentu rusiavimas: 0 ms
Failu isvedimas:  4175 ms
Visa trukme:  51235 ms


studList10000000.txt “6 studList10000000.txt 1 3”

![image](https://github.com/user-attachments/assets/cb185b99-9566-4ab4-aea2-f0fbed3e5820)

Duomenu nuskaitymas: 388998 ms
Studentu rusiavimas: 0 ms
Failu isvedimas:  42907 ms
Visa trukme:  516780 ms
