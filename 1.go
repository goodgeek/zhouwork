package main

import (
	"fmt"
)

type person struct {
	name string
	age  int
}

func main() {
	maplist := make([]string, 10)
	maplist[0] = "google map"

	human := make([]person, 3)
	human[0].name = "zhou"
	human[0].age = 20

	for {
		fmt.Println("hello world！")
	}

	fmt.Println("MapList Size: ", len(maplist))
	for _, v := range maplist {
		if v != "" {
			fmt.Println(v)
		}
	}
}
