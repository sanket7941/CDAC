function add(p1, p2) {
    return p1 + p2;
}

function subtract(p1, p2) {
    return p1 - p2;
}

function multiply(p1, p2) {
    return p1 * p2;
}

// module.exports = add;
// module.exports = subtract;

module.exports = {
    "add": add,
    "subtract": subtract,
    "multiply": multiply
};

// console.log(module);
