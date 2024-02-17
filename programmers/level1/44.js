function solution(a, b) {
  const months = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
  const dayNames = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
  let totalDays = b + 4;
  for (let i = 0; i < a - 1; ++i) {
    totalDays += months[i];
  }
  const dayIndex = totalDays % 7;
  return dayNames[dayIndex];
}
