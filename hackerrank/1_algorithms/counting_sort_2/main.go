package main

import (
	"fmt"
	"sort"
)

// Constraints
const MAX_ARRAY = 100

type largeSlice []int32

func(s largeSlice) Len() int {
	return len(s)
}

func(s largeSlice) Less(i, j int) bool {
	return s[i] < s[j]
}

func(s largeSlice) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

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
	sort.Slice(arr, func(i,j int) bool {
		return arr[i] < arr[j]
	})
	fmt.Println(arr)
}