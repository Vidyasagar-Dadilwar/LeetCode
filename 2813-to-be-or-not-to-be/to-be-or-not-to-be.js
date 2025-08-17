/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    let n = val;
    return {
        toBe: function toBe(val){
            if(val === n)
                return true;
            else
                throw new Error("Not Equal");
        },
        
        notToBe: function notToBe(val){
            if(val !== n)
                return true;
            else
                throw new Error("Equal");
        }
    }  
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */