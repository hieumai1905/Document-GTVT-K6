using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Ogani.Models;
using X.PagedList;

namespace Ogani.Controllers;

public class HomeController : Controller
{
    private readonly QlbanVaLiContext _context;
    private readonly ILogger<HomeController> _logger;

    public HomeController(ILogger<HomeController> logger)
    {
        _logger = logger;
        _context = new QlbanVaLiContext();
    }

    public IActionResult Index(int? page)
    {
        int pageNumber = (int)(page == null || page <= 0 ? 1 : page.Value);
        int pageSize = 8;
        var products = _context.TDanhMucSps.AsNoTracking().OrderBy(x => x.TenSp);
        PagedList<TDanhMucSp> pages = new PagedList<TDanhMucSp>(products, pageNumber, pageSize);
        return View(pages);
    }

    public IActionResult Cate(String maloai, int? page)
    {
        int pageNumber = (int)(page == null || page <= 0 ? 1 : page.Value);
        int pageSize = 8;
        var products = _context.TDanhMucSps.AsNoTracking().Where(x => x.MaLoai == maloai);
        PagedList<TDanhMucSp> pages = new PagedList<TDanhMucSp>(products, pageNumber, pageSize);
        ViewBag.maloai = maloai;
        return View(pages);
    }

    public IActionResult Privacy()
    {
        return View();
    }

    [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
    public IActionResult Error()
    {
        return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
    }
}