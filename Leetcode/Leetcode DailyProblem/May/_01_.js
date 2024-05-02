/**
 * @param {string} word
 * @param {character} ch
 * @return {string}
 */
var reversePrefix = function (word, ch) {
    let n = word.length;
    for (let i = 0; i < n; i++) {
        if (word[i] === ch) {
            return word.slice(0, i).reverse() + word.slice(i);
        }
    }
    return word;
};