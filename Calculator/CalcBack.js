function clr(){
    document.querySelector("#inp").value="";
}
function conct(n){
    document.querySelector("#inp").value+=n;
}
function sign(){
    if(document.querySelector('#inp').value[0]=='-'){
        document.querySelector('#inp').value= document.querySelector('#inp').value.replace('-','+');
    }
    else if(document.querySelector('#inp').value[0]=='+'){
        document.querySelector('#inp').value= document.querySelector('#inp').value.replace('+','-');
    }
    else{
        document.querySelector('#inp').value= '-' + document.querySelector('#inp').value;
    }
}
function del(){
    document.querySelector('#inp').value= document.querySelector('#inp').value.slice(0,-1);
}
function calc(){
    document.querySelector('#inp').value= eval(document.querySelector('#inp').value);
}