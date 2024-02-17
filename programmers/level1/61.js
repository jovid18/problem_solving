function convertDateToDays(dateString) {
  const parts = dateString.split(".");
  const year = Number(parts[0]);
  const month = Number(parts[1]);
  const day = Number(parts[2]);
  return year * 28 * 12 + month * 28 + day;
}

function solution(today, terms, privacies) {
  const todayInDays = convertDateToDays(today);
  let termDurations = {};
  terms.forEach((term) => {
    const termCode = term[0];
    const termDuration = Number(term.slice(1));
    termDurations[termCode] = termDuration;
  });
  var answer = [];
  privacies.forEach((privacy, idx) => {
    const privacyParts = privacy.split(" ");
    const privacyDate = privacyParts[0];
    const privacyCode = privacyParts[1];
    const privacyDateInDays = convertDateToDays(privacyDate);
    const dayDifference = todayInDays - privacyDateInDays;
    if (dayDifference >= termDurations[privacyCode] * 28) {
      answer.push(idx + 1);
    }
  });
  return answer;
}
