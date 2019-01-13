function add(p1,p2)
{
    return p1 +p2;
}

function subtract(p1, p2) 
{
    return p1 - p2;
}

function executor(func){
    console.log("inside executerr");
    console.log(`typeof func = ${typeof(func)}`);
    console.log(`func(10, 20) = ${func(10, 20)}`);
    console.log(`func(30, 40) = ${func(30, 40)}`);
    console.log(`func(50, 60) = ${func(50, 60)}`);
    console.log(`func(70, 80) = ${func(70, 80)}`);
}

executor(add);
executor(subtract);