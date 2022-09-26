package main

import (
	"fmt"
	"strings"
	// "time"
)

func test_case(s string) int32 {
	var p strings.Builder
	var cost int32

	// start := time.Now()

	length := len(s)

	for i := 0; i < length; i++ {
		newChar := fmt.Sprintf("%c", s[i])
		
		substring := strings.Contains(p.String(), newChar)
		
		if !substring {
			cost += 1
		}
		
		p.WriteString(newChar)
	}

	// fmt.Printf("\nFunction took: %v \n", time.Since(start))

	return cost
}

func main() {
	var T int

	fmt.Scanf("%d", &T)

	for i := 0; i < T; i++ {
		var input string
		fmt.Scanf("%s", &input)
		result := test_case(input)
		fmt.Println(result)
	}
}