using Microsoft.AspNetCore.Mvc;

namespace WebApplication1.Controllers;

public class NewController : Controller
{
    // GET
    public IActionResult Index()
    {
        ViewData["Message"] = "Hello World";
        ViewBag.Variable = 100;
        return View("Demo");
    }
    
    public IActionResult Demo()
    {
        TempData["data"] = "value";
        return Redirect("Test");
    }

    public IActionResult Test()
    {
        return View("Test");
    }
}