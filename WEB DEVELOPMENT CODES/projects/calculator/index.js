var result =0;
var operand;
var previous;
function addnumber(event) {
    result = result*10;
    result += ((this.innerText)-0);
    screen.innerHTML = result;
}
function mul(a,b) {
    return result = a*b;
}
function process() {
    previous = result;
    result = 0;
    operand = add;
    screen.innerHTML = 0;
}
function add(a,b)
{
    return result = (a+b);
}
function sub(a,b) {
    return result = a - b;
}
function div(a,b) {
    return result = a/b;
}
function mod(a,b) {
    return result =  a%b;
}
function calculator(a,b,opertor) {
    return result = opertor(a,b);
}
function equal() {
    operand(previous,result);
    screen.innerHTML = result;
}
const but = document.getElementsByClassName('number');
const screen = document.getElementById('screen');
for (let i = 0; i < but.length; i++) {
    const x = but[i];
    x.addEventListener('click',addnumber);
}
document.getElementsByClassName('equal')[0].addEventListener('click',equal);
const operor = document.getElementsByClassName('operator');
for (let i = 0; i < operor.length; i++) {
    const iter = operor[i];
    iter.addEventListener('click',process);
}
