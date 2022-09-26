package main

import (
	"fmt"
	"strings"
)

func test_case(s1, s2 string) string {
	var indexLength int
	var provider string
	var stringUnderTest string

	s1Length := len(s1)
	s2Length := len(s2)

	if s1Length < s2Length {
		indexLength = s1Length
		provider = s1
		stringUnderTest = s2
	} else {
		indexLength = s2Length
		provider = s2
		stringUnderTest = s1
	}

	for i := 0; i < indexLength; i++ {
		commonString := strings.Contains(stringUnderTest, fmt.Sprintf("%c", provider[i]))

		if commonString {
			return "YES"
		}
	}

	return "NO"
}

func main() {
	var T int

	fmt.Scanf("%d", &T)

	for i := 0; i < T; i++ {
		var s1, s2 string
		fmt.Scanf("%s", &s1)
		fmt.Scanf("%s", &s2)
		result := test_case(s1,s2)
		fmt.Println(result)
	}
}