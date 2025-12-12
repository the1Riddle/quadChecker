package main

import (
	"fmt"
	"os"
	"strconv"

	"exec_gen/quadF"
)

func main() {
	if len(os.Args) != 3 {
		fmt.Println("Usage: ./program <width> <height>")
		return
	}

	width, err1 := strconv.Atoi(os.Args[1])
	height, err2 := strconv.Atoi(os.Args[2])
	if err1 != nil || err2 != nil {
		fmt.Println("Width and height must be integers")
		return
	}

	quadF.QuadD(width, height)
}
