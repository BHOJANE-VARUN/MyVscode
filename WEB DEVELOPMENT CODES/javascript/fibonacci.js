var num = 10;
var prev = 0,cur = 1;
console.log(0);
console.log(1);
for(var i =2;i<num;i++)
{
    console.log(cur+prev);
    var temp = prev;
    prev = cur;
    cur = temp+cur;
}