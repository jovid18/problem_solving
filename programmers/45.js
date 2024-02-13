function solution(cards1, cards2, goal) {
  if (goal.length === 0) return "Yes";
  let ans1 = "No";
  let ans2 = "No";
  if (cards1.length > 0 && cards1[0] === goal[0]) {
    ans1 = solution(cards1.slice(1), cards2, goal.slice(1));
  }
  if (cards2.length > 0 && cards2[0] === goal[0]) {
    ans2 = solution(cards1, cards2.slice(1), goal.slice(1));
  }
  if (ans1 === "Yes" || ans2 === "Yes") return "Yes";
  return "No";
}
