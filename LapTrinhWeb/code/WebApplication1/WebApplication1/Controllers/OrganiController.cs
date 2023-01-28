using Microsoft.AspNetCore.Mvc;

namespace WebApplication1.Controllers;

public class OrganiController : Controller
{
    // GET
    public IActionResult Index()
    {
        return View();
    }
}