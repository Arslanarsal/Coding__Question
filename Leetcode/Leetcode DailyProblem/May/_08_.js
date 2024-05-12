/**
 * @param {number[]} score
 * @return {string[]}
 */
var findRelativeRanks = function (score) {
    const lenScore = score.length;
    const answer = new Array(lenScore);
    const scoreWithIndex = score.map((score, index) => [score, index]);

    // Sort the score in descending order
    scoreWithIndex.sort((a, b) => b[0] - a[0]);

    const rank = ["Gold Medal", "Silver Medal", "Bronze Medal"];

    // Assign ranks based on sorted score
    for (let i = 0; i < lenScore; i++) {
        const index = scoreWithIndex[i][1];
        if (i < 3) {
            answer[index] = rank[i];
        } else {
            answer[index] = String(i + 1);
        }
    }

    return answer;
};