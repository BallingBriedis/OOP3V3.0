# **Releases**

| Version   | Functions                                                                                                                                                                                                                                                  | Comments                                                                                                              |
| --------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------- |
| v.pradinė | Duomenų įvedimas. Studentų duomenų struktūra. Skaičiavimo funkcijos.                                                                                                                                                                                       | Viskas įvyko sklandžiai. Komentarų nėra                                                                               |
| v0.1      | Galimybė įvesti bet kokį kiekį studentų, nes naudojami STL konteineriai. Versija su dinaminiu masyvu. Atsitiktinis pažymių generavimas. Meniu.                                                                                                             | Pirma kartą naudojau STL konteinerius, jie smarkiai palengvina darbą.                                                 |
| v0.2      | Sąveika su failais. Rušiavimas pagal pasirinkimą.                                                                                                                                                                                                          | Nieko specialaus, bet reikėjo kodo architektūros perdarymo įskaitomumui                                               |
| v0.3      | Naudojama išimčių valdymas.                                                                                                                                                                                                                                | Iš pradžių nenorėjau naudoti exep.handling, bet pabandžius buvo paprasta ir pagražino kodo išvazdą.                   |
| v0.4      | Studentų generavimas. Failų generavimas. Studentų rušiavimo funkcija. Testavimo funkcija. Tyrimo README.md aprašas.                                                                                                                                        | Užtruko labai daug laiko, nes buvo nemažai klaidų, teko daug testuoti. Galū gale viskas išėjo sklandžiai.             |
| v1.0      | Naudojama CMake. Trys skirtingos versijos su skirtingais STL konteineriais: List, Deque ir Vector. Spartumo tyrimai. Naudojami specialūs algoritmai Vector versijoje. Sutvarkyta repozitorija. Viso projekto aprašas. Naudojimosi ir diegimo instrukcijos. | Užtruko dar daugiau laiko dėl testavimo ir šios versijos monotoniško darbo. Darbas pavyko.                            |
| v1.1      | Pakeista kodo struktura, implementuota klasė vietoj prieštai naudoto struct                                                                                                                                                                                | Pradėti su klasėm nesinorėjo, bet vertėjo kodo aiškumui ir spartesniam kurimui                                        |
| v1.2      | Implementuota Rules of Five, perkrautas Ivesties operatorius ir perkrautas Išvesties operatorius. Testai turi menu, padaryti testai programos testavimo palengvinimui.                                                                                     | Versija padaryta greitai, bet naudingai                                                                               |
| v1.5      | Sukurtos abstrakti bazinė Zmogus ir išvestinė Stud klasės.                                                                                                                                                                                                 | Greičiausia padaryta versija, supratimas apie bazines ir išvestines klases tikrai padidėjo. Testų keisti nereikėjo :) |
| v2.0      | Sukurta HTML, LaTeX PDF dokumentacija naudojant Doxygen programėlę. Implementuoti Stud klasės Unit Testai naudojant "googletest" projektą.                                                                                                                 | Dėl korumpuotų failų ir nepastabumo šita versija buvo blogiausia patirtis. Bet galų gale viskas pavyko sekmingai.     |
| v3.0      | Sukuriau savo custom Vector klasę, atkartota didelė dalis STL vector funkcijų. Unit testai nuosavai vector funkcijai. Testavimas. Installeris.                                                                                                             | Daug laiko užtruko, sudėtinga pradėti, bet atradus internetinius šaltinius pasidare lengviau.                         |


# **Starting manual**

Atsisiūsti v3.0 full release.

Naudojant WinRAR arba 7-Zip, atskleisti (extract) failą, bus sukurtas aplankas su programos failais.

## **Pirmas būdas (Lengvesnis)**
Paleidi "V1.5 OOP.msi" failą, nekeisti atsisiuntimo direktorijos.

Siuntimuisi baigus, į "C:\Program Files\Vilniaus Universitetas\V1.5 OOP" įsidėkite "studList10000.txt" ir "studList100000.txt".

Paleidžiamąją programą rasite "Start menu" ir Darbalaukyje.

## **Antras būdas**

"dependancies" aplanke įsidiegti "cmake-4.0.0-rc4-windows-x86_64.msi".

Atidarai aplanką VECTOR, paleidi run.bat scriptą.

Atsidarys "cmd" langas kuriame bus veikianti programa, pirma kartą pasileidus dar vyks unit testas. Jeigu programą uždarėte ir norite vėl ją atidaryti, tai nuo tos vietos kur yra run.bat paspauskite "build" aplanką, tada "Release" aplanką kuriame rasite "OOP3V30.exe" paleidžiamąjį failą.


# **User manual**

1 - Ranka įvedamas studentas ir jo pažymiai.

2 - Ranka įvedamas studento vardas/pavardė, pažymys generuojamas.

3 - Studentas(-ai) sukuriami automatiškai, tik reikia įvesti studentų kiekį.

4 - Failas, esantis aplanke kartu su "OOP3V30.exe" ( ...\VECTOR\build\Release ) yra nuskaitomas į tam tikrą konteinerį.

5 - Sukuriamas failas pavadinimu "studList{įvestasStudentuKiekis}.txt"

6 - Atidaromas testinis menu

7 - Tęsiama toliau, grįžti negalima.

7.1-7.3 - Pasirinkimai ar isvesti i terminala, i faila arba i faila suskirstytus

7.x.1-7.x.3 - Pasirinkimai apskaičiuoti galutinius pažymius vidurkiu arba mediana arba abu

7.x.x.1-7.x.x.4 - Pasirinkimai pagal ką norite rušiuoti studentus.

Rezultatų failą rasite ( ...\VECTOR\build\Release ).


# **5 Funkcijų aprašymai**
| Reserve    | void Reserve(size_t newCapacity); Ši funkcija naudojama užrezervuoti pateiktą "vietų" (newCapacity) atmintyje. Funkcija gauna reikšmę newCapacity, kurią lyginu su esančia capacity reikšme, jeigu newCapacity mažesnis, tai funkcijas grįžta. Kitaip ji sukuria new newArray, kurią užpildo array, array išsitrina ir atgauna savo reikšmes. |
| ---------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| PushBack   | void PushBack(const T& value); Ši funkcija priima value, kuri įstato į Vectoriaus galą. Pirma - patikrina ar size >= capacity, jei taip, tai padidina array ir toliau eina, kur array paskutine vietele idedama value.                                                                                                                        |
| operator== | bool operator==(const Vector& rhs) const; Ši funkcija priima rhs reikšmę, kurią lygina su pradines reikšmės size, tada array elementais ir jeigu abu neismete false, duoda true.                                                                                                                                                              |
| Vector     | Vector(const std::initializer_list<T>& list); Ši funkcija leidžia inicijuoti reikšmes pvz.: Vector<int> SK {1,2,3,4,5}. Pirma paima size(0), tada capacity yra pagal paduota list ilgi + 5, sukuriama array dinaminej atminty ir PushBack funkcija prideda visas reikšmes prie array.                                                         |
| At         | T& At(size_t index); Priima indeksa, pagal kuri gražina elementa toj vietoj, jeigu indeksas neišeina iš Vectoriaus ribų.                                                                                                                                                                                                                      |


# **Vector compare test**
| Fill size     | My vector      | STL vector     |
| ------------- | -------------- | -------------- |
| 10000         | 0.00004790 sec | 0.00005380 sec |
| 100000        | 0.00037480 sec | 0.00041790 sec |
| 1000000       | 0.00198310 sec | 0.00290890 sec |
| 10000000      | 0.01952810 sec | 0.03320920 sec |
| 100000000     | 0.30923830 sec | 0.35358800 sec |
| AVG           | 0.06051138 sec | 0.07803556 sec |
| TOTAL         | 0.30636120 sec | 0.39470780 sec |
| Perskirstymai | 25 kartai      | 46 kartai      |


Kiekvienas failas nuskaitytas po 3 kartus.
| File size     | My vector (AVG) | My vector (TOT)   | STL vector (FUN) | STL vector (AVG) | STL vector (TOT)  | STL vector (FUN) |
| ------------- | --------------- | ----------------- | ---------------- | ---------------- | ----------------- | ---------------- |
| 100000        | 0.42521847 sec  | 1.27565540 sec    | 0.37621842 sec   | 0.41326590 sec   | 1.23979770 sec    | 0.35512627 sec   |
| 1000000       | 4.52487077 sec  | 13.57461230 sec   | 4.02434072 sec   | 4.48646507 sec   | 13.45939520 sec   | 3.62357066 sec   |
| 10000000      | 49.94290833 sec | 149.82872500 sec  | 37.95690113 sec  | 41.98002827 sec  | 125.94008480 sec  | 36.44295553 sec  |

Nuskaityme vienintele Vector funkcija naudojama yra push_back, arba PushBack, tikslaus laiko negausiu, bet operacija kuri suskirsto duomenis ivyksta yra pateikta.
Po šios analizės paaiškėjo, kad aš nesu geresnis Vector klasės kurėjas negu žmonės susiėmę STL.


# **Unit testing**
Unit testai vykdomi pirmą kartą paleidus run.bat failą ir priešais pagrindinę programą.


# **Klasės naudojimas**

## **Išvesties operatorius**

Išvesties operatorius perdengtas, naudojimas labai paprastas:

Stud studentas(Jonas, Jonaitis, 8, 5, 6, 7);

std::cout << studentas;

Tai padarant išves duotus duomenis apie studentą, jo vidurkį ir medianą.


## **Ivesties operatorius**

Irgi labai paprastas naudojimas, rankiniu būdu parašant "std::cin >> studentas;" terminale prašys vartotojo įvesti duomenis.

Stud studentas;

std::cin >> studentas;

### Kiti būdai įvesties
Iš failo įvestis daroma naudojant fileRead() funkciją. Norint nuskaityti savus failus, reikia pateikti juos ( ...\build\Release\test.txt ) formatu (studentu kiekis nesvarbu) ir idėti į ( ...\VECTOR\build\Release ).

Automatinė daroma naudojant makeStud() funkciją.


# **V1.1 testas**

| Part | Specifications 				 |
| ---- | ------------------------------- |
| CPU: | Intel i5-10600K				 |
| RAM: | 2x16GB 2666MHz DDR4			 |
| STR: | Kingston NV2 1 TB M.2 2280 NVMe |

| Flagai   | 100000 (Struct) | 1000000 (Struct) | EXE size (Struct) | 100000 (Class) | 1000000 (Class) | EXE size (Class) |
| -------- | --------------- | ---------------- | ----------------- | -------------- | --------------- | ---------------- |
| Be flagu | 0.44610952 sec  | 4.20656290 sec   | 127 KB     		| 0.44792966 sec | 4.39760216 sec  | 141 KB           |
| O1   	   | 0.44192624 sec  | 4.05293074 sec   | 119 KB     		| 0.43307130 sec | 4.24400640 sec  | 129 KB           |
| O2   	   | 0.40628492 sec  | 4.08120978 sec   | 119 KB     		| 0.43038714 sec | 4.25291338 sec  | 129 KB           |
| O3  	   | 0.43692144 sec  | 4.35214120 sec   | 119 KB     		| 0.44872598 sec | 4.40468464 sec  | 129 KB           |


# **V1.0 testas**

## **Pradžia**
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

## **Vector**

| Failo dydis  	| Pirma strategija 	| Antra strategija 	   |
| ------------- | ----------------- | -------------------- |
| 1000     	    | 0.04915840 sec    | 0.08148740 sec       |
| 10000   	    | 0.43130660 sec    | 0.45130710 sec       |
| 100000   	    | 4.46657050 sec    | 4.48731360 sec       |
| 1000000  	    | 41.31402830 sec   | 42.56847090 sec      |
| 10000000 	    | 424.58098150 sec  | 431.82273370 sec     |

10 milijonų su pirma strategija užemė 7.7GB RAM, o antra 5.9GB RAM.

## **List**

| Failo dydis  	| Pirma strategija 	| Antra strategija 	   |
| ------------- | ----------------- | -------------------- |
| 1000     	    | 0.05118660 sec    | 0.08393100 sec       |
| 10000   	    | 0.37497380 sec    | 0.37388180 sec       |
| 100000   	    | 3.70634520 sec    | 3.53147080 sec       |
| 1000000  	    | 35.40114870 sec   | 35.71196400 sec      |
| 10000000 	    | 350.78200190 sec  | 361.86110030 sec     |

10 milijonų su pirma strategija užemė 6.1GB RAM, o antra 5.3GB RAM.

## **Deque**

| Failo dydis  	| Pirma strategija 	| Antra strategija 	   |
| ------------- | ----------------- | -------------------- |
| 1000     	    | 0.05772800 sec    | 0.05651100 sec       |
| 10000   	    | 0.39833120 sec    | 0.41024440 sec       |
| 100000   	    | 3.76838590 sec    | 4.06764040 sec       |
| 1000000  	    | 37.04322620 sec   | 39.36357640 sec      |
| 10000000 	    | 373.31425860 sec  | 394.22153330 sec     |

10 milijonų su pirma strategija užemė 10.1GB RAM, o antra 6.8GB RAM.
