package main

import (
	"go-fiber-api/api"
)

func main() {
	app := api.SetupRoute()

	//app.Get("/", func(c *fiber.Ctx) error {
	//	return c.SendString("Welcome to Go Fiber API")
	//	//
	//	//})

	app.Listen(":5000")
}
