# **Releases**

| Version   | Functions                                                                                                                                                                                                                                                  | Comments                                                                                                  |
| --------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------- |
| v.pradinė | Duomenų įvedimas. Studentų duomenų struktūra. Skaičiavimo funkcijos.                                                                                                                                                                                       | Viskas įvyko sklandžiai. Komentarų nėra                                                                   |
| v0.1      | Galimybė įvesti bet kokį kiekį studentų, nes naudojami STL konteineriai. Versija su dinaminiu masyvu. Atsitiktinis pažymių generavimas. Meniu.                                                                                                             | Pirma kartą naudojau STL konteinerius, jie smarkiai palengvina darbą.                                     |
| v0.2      | Sąveika su failais. Rušiavimas pagal pasirinkimą.                                                                                                                                                                                                          | Nieko specialaus, bet reikėjo kodo architektūros perdarymo įskaitomumui                                   |
| v0.3      | Naudojama išimčių valdymas.                                                                                                                                                                                                                                | Išpradžių nenorėjau naudoti exep.handling, bet pabandžius buvo paprasta ir pagražino kodo išvazdą.        |
| v0.4      | Studentų generavimas. Failų generavimas. Studentų rušiavimo funkcija. Testavimo funkcija. Tyrimo README.md aprašas.                                                                                                                                        | Užtruko labai daug laiko, nes buvo nemažai klaidų, teko daug testuoti. Galū gale viskas išėjo sklandžiai. |
| v1.0      | Naudojama CMake. Trys skirtingos versijos su skirtingais STL konteineriais: List, Deque ir Vector. Spartumo tyrimai. Naudojami specialūs algoritmai Vector versijoje. Sutvarkyta repozitorija. Viso projekto aprašas. Naudojimosi ir diegimo instrukcijos. | Užtruko dar daugiau laiko dėl testavimo ir šios versijos monotoniško darbo. Darbas pavyko.                |

# **Starting manual**

Atsisiūsti v1.0 full release.

Naudojant WinRAR arba 7-Zip, atskleisti (extract) failą, bus sukurtas aplankas su programos failais.

"dependancies" aplanke įsidiegti "cmake-4.0.0-rc4-windows-x86_64.msi".

Pasirinkti norimą konteinerio tipo versiją: LIST, DEQUE , VECTOR.

Atidarai aplanką, paleidi run.bat scriptą.

Atsidarys "cmd" langas kuriame bus veikianti programa, jeigu programą uždarėte ir norite vėl ją atidaryti, tai nuo tos vietos kur yra run.bat paspauskite "build" aplanką, tada "Debug" aplanką, kuriame rasite "MyContainerExecutable.exe" paleidžiamąjį failą.


# **User manual**

1 - Ranka įvedamas studentas ir jo pažymiai.

2 - Ranka įvedamas studento vardas/pavardė, pažymys generuojamas.

3 - Studentas(-ai) sukuriami automatiškai, tik reikia įvesti studentų kiekį.

4 - Failas, esantis aplanke kartu su "MyContainerExecutable.exe" ( ...\{SelectedContainer}\build\Debug ) yra nuskaitomas į tam tikrą konteinerį.

5 - Sukuriamas failas pavadinimu "studList{įvestasStudentuKiekis}.txt"

6 - Suskirto faile esančius studentus į mokslinčių ir vargšiukų failus pagal jų galutinį pažymį.

7 - Naudojamas matuoti nuskaitymo laiką, galima įvesti kiek kartu nori teksto failą skaityti.

8 - Tęsiama toliau, grįžti negalima.

8.1-8.4 - Pasirinkimai apskaičiuoti galutinius pažymius vidurkiu arba mediana ir kokios išvesties norite. 

8.x.1-8.x.3 - Pasirinkimai pagal ką norite rušiuoti studentus.

Rezultatų failą rasite ( ...\{SelectedContainer}\build\Debug ).


# **Pradžia**
| Part | Specifications 				 |
| ---- | ------------------------------- |
| CPU: | Intel i5-10600K				 |
| RAM: | 2x16GB 2666MHz DDR4			 |
| STR: | Kingston NV2 1 TB M.2 2280 NVMe |

Įvestis:

1 Strategija:

6 studList1000.txt 1 1 3

6 studList10000.txt 1 1 3

6 studList100000.txt 1 1 3

6 studList1000000.txt 1 1 3

6 studList10000000.txt 1 1 3

2 Strategija:

6 studList1000.txt 1 2 3

6 studList10000.txt 1 2 3

6 studList100000.txt 1 2 3

6 studList1000000.txt 1 2 3

6 studList10000000.txt 1 2 3

# **Vector**

| Failo dydis  	| Pirma strategija 	| Antra strategija 	   |
| ------------- | ----------------- | -------------------- |
| 1000     	    | 0.04915840 sec    | 0.08148740 sec       |
| 10000   	    | 0.43130660 sec    | 0.45130710 sec       |
| 100000   	    | 4.46657050 sec    | 4.48731360 sec       |
| 1000000  	    | 41.31402830 sec   | 42.56847090 sec      |
| 10000000 	    | 424.58098150 sec  | 431.82273370 sec     |

10 milijonų su pirma strategija užemė 7.7GB RAM, o antra 5.9GB RAM.

# **List**

| Failo dydis  	| Pirma strategija 	| Antra strategija 	   |
| ------------- | ----------------- | -------------------- |
| 1000     	    | 0.05118660 sec    | 0.08393100 sec       |
| 10000   	    | 0.37497380 sec    | 0.37388180 sec       |
| 100000   	    | 3.70634520 sec    | 3.53147080 sec       |
| 1000000  	    | 35.40114870 sec   | 35.71196400 sec      |
| 10000000 	    | 350.78200190 sec  | 361.86110030 sec     |

10 milijonų su pirma strategija užemė 6.1GB RAM, o antra 5.3GB RAM.

# **Deque**

| Failo dydis  	| Pirma strategija 	| Antra strategija 	   |
| ------------- | ----------------- | -------------------- |
| 1000     	    | 0.05772800 sec    | 0.05651100 sec       |
| 10000   	    | 0.39833120 sec    | 0.41024440 sec       |
| 100000   	    | 3.76838590 sec    | 4.06764040 sec       |
| 1000000  	    | 37.04322620 sec   | 39.36357640 sec      |
| 10000000 	    | 373.31425860 sec  | 394.22153330 sec     |

10 milijonų su pirma strategija užemė 10.1GB RAM, o antra 6.8GB RAM.
