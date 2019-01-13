function add(p1,p2){
    return p1+p2;
}

console.log(`add = ${add(10,20)}`);

//function alise 
var myAdd = add;

console.log(`myAdd = ${myAdd(10,20)}`);

// unanmes/Anonymous function

var multiply = function(p1,p2)
{
    return p1 * p2;
}

console.log(`multiply = ${multiply(4, 5)}`);

// arrow function 

var division =(p1,p2)=>
{
    return p1/p2;
};

console.log(`division = ${division(10, 5)}`);