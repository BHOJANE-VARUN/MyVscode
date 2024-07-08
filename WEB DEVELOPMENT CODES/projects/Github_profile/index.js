const url_base = "https://api.github.com/users/";
async function getuserinfo(urll)
{
    const info = await fetch(urll);
    var obj = await info.json();
    console.log(obj);
    const imgclass = document.getElementsByClassName('userimg')[0];
    imgclass.innerHTML = "<img src=\"" + obj["avatar_url"] + "\" alt=\"Profile_Picture\"></img>";
    const name = document.getElementById('name');
    name.innerHTML = obj["name"];
    const bio = document.getElementById('bio');
    bio.innerHTML = obj["bio"];
    const follwers = document.getElementById('follwers');
    follwers.innerHTML = obj["followers"];
    const follwing = document.getElementById('following');
    follwing.innerHTML = obj["following"];
    const repo = document.getElementById('repo');
    repo.innerHTML = obj["public_repos"];
    const work = await fetch(obj["repos_url"]);
    var wor = await work.json();
    console.log(wor.length);
    const tag = document.getElementById('tag');
    let str = "";
    for(let i =0;i<Math.min(wor.length,5);i++)
    {
        str += "<span class=\"tags\">"+wor[i]["name"] +"</span>";
    }
    tag.innerHTML = str;
}
document.addEventListener('DOMContentLoaded', (event) => {
    const input = document.getElementsByClassName('butt')[0];
  
    input.addEventListener('keypress', (event) => {
      if (event.key === 'Enter') {
        getuserinfo(url_base+input.value);
      }
    });
  });
