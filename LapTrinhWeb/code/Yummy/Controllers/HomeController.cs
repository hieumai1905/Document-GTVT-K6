using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using Yummy.Models;

namespace Yummy.Controllers;

public class HomeController : Controller
{
    private readonly ILogger<HomeController> _logger;

    public HomeController(ILogger<HomeController> logger)
    {
        _logger = logger;
    }

    public IActionResult Index()
    {
        return View();
    }

    public IActionResult Privacy()
    {
        return View();
    }

    public IActionResult Sample()
    {
        return View("sample-inner-page");
    }

    public IActionResult TestModel()
    {
        var user = new User();
        user.id = 1;
        user.name = "John";
        user.email = "maivan@gmail.com";
        var account = new Account("username", "password");
        
        // Chuyển đổi model sang object
        object oUser = user;
        object oAccount = account;
        
        // Tạo list Object
        List<object> list = new List<object>();
        list.Add(user);
        list.Add(account);
        
        return View(list);
    }

    [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
    public IActionResult Error()
    {
        return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
    }
}