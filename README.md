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
