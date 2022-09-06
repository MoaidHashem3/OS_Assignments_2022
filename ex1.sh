ls /usr/bin > list
grep gcc list > list2
ls | tail -n 5 list2 > list3
ls | sort -r list3 > ex1.txt
