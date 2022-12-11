package main

func main() {
	var num, numPlus, total uint = 1, 2, 0

	for numPlus <= 4000000 {
		if num&1 == 0 {
			total += num
		}
		num, numPlus = numPlus, num+numPlus
	}

	println(total)
}
