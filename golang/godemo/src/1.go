package main

import (
	"fmt"
	"net"
)

func main() {
	conn, err := net.Dial("tcp4", "127.0.0.1:8003")
	if err != nil {
		fmt.Println("Dail tcp failed" + err.Error())
		return
	}
	defer conn.Close()

	conn.Write([]byte("hello"))
}
