package main

import (
	"fmt"
	"sort"
)

type Number struct {
	Value int
	Frequency int
}

type ByFrequency []Number

func (f ByFrequency) Len() int 			 { return len(f) }
func (f ByFrequency) Swap(i, j int)      { f[i], f[j] = f[j], f[i]}
func (f ByFrequency) Less(i, j int) bool { 
	less := f[i].Frequency < f[j].Frequency
	if f[i].Frequency == f[j].Frequency {
		less = f[i].Value < f[j].Value
	}
	return less
}

func main() {
	var T int

	fmt.Scanf("%d", &T)

	items := make([]int, T)
	
	for tc := 1; tc <= T; tc++ {
		var input int
		fmt.Scanf("%d", &input)
		items[tc-1] = input
	}

	test_case(items)
}

func test_case(items []int) {
	_map := make(map[int]int)

	for _, number := range items {
		if value, exist := _map[number]; !exist {
			_map[number] = 1
		} else {
			_map[number] = value + 1		
		}
	}

	numbers := make([]Number, len(_map))

	index := 0
	for key, value := range _map {
		numbers[index] = Number{key, value}
		index++
	}	

	sort.Sort(ByFrequency(numbers))

	for _, data := range numbers {
		if(data.Frequency > 1) {
			for i := 1; i <= data.Frequency; i++ {
				fmt.Println(data.Value)
			}
		} else {
			fmt.Println(data.Value)
		}
	}
}