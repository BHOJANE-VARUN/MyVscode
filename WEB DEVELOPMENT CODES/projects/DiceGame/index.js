var num = Math.random();
var num2 = Math.random();
num *= 6;
num2 *= 6;
num = Math.floor(num);
num2 = Math.floor(num2);
var links = ["one.png","two.jfif","three.jfif","four.jpg","five.jfif","six.svg"];
var ele1 = document.getElementById("imof1");
var ele2 = document.getElementById("imof2");
ele1.innerHTML = "<img src=\"" + links[num] +  "\" alt=\"imgofsomethin\">";
ele2.innerHTML = "<img src=\"" + links[num2] +  "\" alt=\"imgofsomethin\">";
var text = document.getElementById("after");
if(num>num2)
{
    text.innerText = "PLAYER 1🎉";
}
else if(num==num2)
{
    text.innerText = "Nobody wins🎉";
}
else{
    text.innerText = "PLAYER 2🎉";
}




