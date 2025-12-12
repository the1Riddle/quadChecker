package main

import (
	"fmt"
	"io"
	"os"
	"sort"
	"strings"
)

type QuadStyle struct {
	TL string
	TR string
	BL string
	BR string
	H  string
	V  string
	F  string
}

func drawQuad(width, height int, s QuadStyle) string {
	if width <= 0 || height <= 0 {
		return ""
	}

	var result strings.Builder

	for row := 0; row < height; row++ {
		for col := 0; col < width; col++ {
			isTop := row == 0 // type bool
			isBottom := row == height-1
			isLeft := col == 0
			isRight := col == width-1

			switch {
			case isTop && isLeft:
				result.WriteString(s.TL)
			case isTop && isRight:
				result.WriteString(s.TR)
			case isBottom && isLeft:
				result.WriteString(s.BL)
			case isBottom && isRight:
				result.WriteString(s.BR)
			case isTop || isBottom:
				result.WriteString(s.H)
			case isLeft || isRight:
				result.WriteString(s.V)
			default:
				result.WriteString(s.F)
			}
		}
		result.WriteByte('\n')
	}

	return result.String() // o---o\n|   |\no---o\n
}

var quadAStyle = QuadStyle{
	TL: "o", TR: "o", BL: "o", BR: "o",
	H: "-", V: "|", F: " ",
}

var quadBStyle = QuadStyle{
	TL: "/", TR: "\\", BL: "\\", BR: "/",
	H: "*", V: "*", F: " ",
}

var quadCStyle = QuadStyle{
	TL: "A", TR: "A", BL: "C", BR: "C",
	H: "B", V: "B", F: " ",
}

var quadDStyle = QuadStyle{
	TL: "A", TR: "C", BL: "A", BR: "C",
	H: "B", V: "B", F: " ",
}

var quadEStyle = QuadStyle{
	TL: "A", TR: "C", BL: "C", BR: "A",
	H: "B", V: "B", F: " ",
}

func isValid(input string) ([]string, bool) {
	matches := []string{}
	input = strings.TrimRight(input, "\n\r")
	if len(input) == 0 {
		return nil, false
	}

	lines := strings.Split(input, "\n") // "ab\nbb\ncd" == [ab bb cd]
	width := len(lines[0])
	height := len(lines)

	for _, line := range lines {
		if len(line) != width {
			return nil, false
		}
	}

	quads := map[string]QuadStyle{
		"quadA": quadAStyle,
		"quadB": quadBStyle,
		"quadC": quadCStyle,
		"quadD": quadDStyle,
		"quadE": quadEStyle,
	}

	for name, style := range quads {
		generated := drawQuad(width, height, style)
		generated = strings.TrimRight(generated, "\n")
		if generated == input {
			matches = append(matches, fmt.Sprintf("[%s] [%d] [%d]", name, width, height))
		}
	}

	if len(matches) == 0 {
		return nil, false
	}

	sort.Strings(matches)
	return matches, true
}

func main() {
	info, err := io.ReadAll(os.Stdin)
	if err != nil || len(info) == 0 {
		fmt.Println("Not a quad function")
		return
	}

	matches, ok := isValid(string(info))
	if !ok {
		fmt.Println("Not a quad function")
		return
	}

	fmt.Println(strings.Join(matches, " || "))
}
