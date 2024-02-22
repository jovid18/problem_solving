function solution(k, score) {
  let answer = [];
  let nums = [];
  score.forEach((num) => {
    nums.push(num);
    nums.sort((a, b) => {
      return a - b;
    });
    if (nums.length > k) nums.splice(0, 1);
    answer.push(nums[0]);
  });
  return answer;
}


