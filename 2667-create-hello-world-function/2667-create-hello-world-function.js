/**
 * @return {Function}
 */
var createHelloWorld = function() {
    function createHelloWorld(){
        return "Hello World";
    }
    return function(...args) {
        const f = createHelloWorld();
        return f;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */