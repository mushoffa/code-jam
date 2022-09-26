package main

import (
	"fmt"
)

// Constraints
const MAX_ARRAY = 100

func main() {
	var T int

	fmt.Scanf("%d", &T)
	items := make([]int32, T)
	
	for tc := 0; tc < T; tc++ {
		var input int32
		fmt.Scanf("%d", &input)
		items[tc] = input
	}

	test_case(items)
}

func test_case(arr []int32) {
	_map := make(map[int32]int32)

	for _, number := range arr {
		if value, exist := _map[number]; !exist {
			_map[number] = 1
		} else {
			_map[number] = value + 1		
		}
	}

	sortedCount := make([]int32, MAX_ARRAY)

	var index int32

	for index = 0; index < MAX_ARRAY; index++ {
		if value, exist := _map[index]; exist {
			sortedCount[index] = value
		} else {
			sortedCount[index] = 0
		}
	}

	for index = 0; index < MAX_ARRAY; index++ {
		fmt.Printf("%d ",sortedCount[index])
	}
}