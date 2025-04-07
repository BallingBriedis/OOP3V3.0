# **Pradžia**
| Part | Specifications 		 |
| ---- | ------------------------------- |
| CPU: | Intel i5-10600K		 |
| RAM: | 2x16GB 2666MHz DDR4		 |
| STR: | Kingston NV2 1 TB M.2 2280 NVMe |

Įvestis:

6 studList1000.txt 1 3

6 studList10000.txt 1 3

6 studList100000.txt 1 3

6 studList1000000.txt 1 3

6 studList10000000.txt 1 3

# **Vector**

| Failo dydis  	| Failo nuskaitymas | Studentų rusiavimas | Studentu skirstymas |
| ------------- | ----------------- | ------------------- | ------------------- |
| 1000     	| 0.03865150 sec    | 0.00145970 sec      | 0.00577600 sec      |
| 10000   	| 0.37697900 sec    | 0.01593270 sec      | 0.06597260 sec      |
| 100000   	| 3.82900110 sec    | 0.16160440 sec      | 0.78876700 sec      |
| 1000000  	| 37.31013170 sec   | 1.64722430 sec      | 6.33887450 sec      |
| 10000000 	| 378.10585340 sec  | 16.41871420 sec     | 66.08117520 sec     |

# **List**

| Failo dydis  	| Failo nuskaitymas | Studentų rusiavimas | Studentu skirstymas |
| ------------- | ----------------- | ------------------- | ------------------- |
| 1000     	| 0.03553050 sec    | 0.00008110 sec      | 0.00217640 sec      |
| 10000   	| 0.35179180 sec    | 0.00116630 sec      | 0.02441840 sec      |
| 100000   	| 3.46478660 sec    | 0.02014820 sec      | 0.24388240 sec      |
| 1000000  	| 35.12424120 sec   | 0.35589710 sec      | 2.85569620 sec      |
| 10000000 	| 351.06966350 sec  | 3.71206090 sec      | 29.49046400 sec     |

# **Deque**

| Failo dydis  	| Failo nuskaitymas | Studentų rusiavimas | Studentu skirstymas |
| ------------- | ----------------- | ------------------- | ------------------- |
| 1000     	| 0.03604740 sec    | 0.00160250 sec      | 0.00455520 sec      |
| 10000   	| 0.35558020 sec    | 0.01842610 sec      | 0.05274180 sec      |
| 100000   	| 3.53771800 sec    | 0.18900190 sec      | 0.59229530 sec      |
| 1000000  	| 35.72011690 sec   | 1.85387040 sec      | 4.90393770 sec      |
| 10000000 	| 346.49843060 sec  | 18.22631840 sec     | 49.01961030 sec     |

# **Summary**

Bendrai pastebėjau, kad 10 milijonų failų ivesties, rusiavimo, skirstymo ir isvesties laikai tarp konteinerių tipų buvo skirtingi.
| Container type | Full time |
| -------------- | --------- |
| Vector	 | 500 sec   |
| List		 | 430 sec   |
| Deque	 	 | 465 sec   |
