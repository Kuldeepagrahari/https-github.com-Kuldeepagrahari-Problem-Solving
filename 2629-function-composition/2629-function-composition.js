/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    const size = functions.length

    return function(x) {
        for(var i = size - 1; i >= 0; i--) {
            x = functions[i](x);
        }
        return x;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */