namespace Yummy.Models;

public class User
{
    public long id { get; set; }
    public string name { get; set; }
    public string email { get; set; }

    public User()
    {
    }

    public User(long id, string name, string email)
    {
        this.id = id;
        this.name = name;
        this.email = email;
    }
}