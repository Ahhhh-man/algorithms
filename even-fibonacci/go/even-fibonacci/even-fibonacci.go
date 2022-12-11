package main

import "fmt"

func main() {
	var num, numPlus uint = 1, 2
	var total uint = 0

	for numPlus <= 4000000 {
		if num%2 == 0 {
			total += num
		}
		num, numPlus = numPlus, num+numPlus
	}
	fmt.Printf("Total is %d\n", total)
}
