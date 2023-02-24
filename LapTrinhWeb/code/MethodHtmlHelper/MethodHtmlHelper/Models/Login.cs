using System.ComponentModel;
using System.ComponentModel.DataAnnotations;

namespace MethodHtmlHelper.Models;

public class Login
{
    [DisplayName("User name")] public string Username { get; set; }

    [DataType(DataType.Password)] // nghĩa là khi nhập password sẽ không hiện ra ký tự
    public string Password { get; set; }

    public Login()
    {
    }

    public Login(string username, string password)
    {
        Username = username;
        Password = password;
    }
}