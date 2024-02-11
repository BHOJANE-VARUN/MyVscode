// var alt = document.getElementById("wbutton");
var ct =0;
var len = document.querySelectorAll(".drum").length;
var arr = document.querySelectorAll(".drum");
//querySelectorAll returns list of the all the objects of the particular id 
for (let i = 0; i<len; i++) {
   let cur = arr[i];
   cur.addEventListener("click",function sendalert() {
    cur.innerText = "we are clicked"+ ct;
    ct++;
});
}
