function[] = sortsPlot(text)

data1 = load(strcat("../Lab3/MergeSortAnalysis/testDatas/", text));
data2 = load(strcat("../Lab3/QuickSortAnalysis/testDatas/", text));
data3 = load(strcat("../Lab4/HeapSortAnalysis/testDatas/", text));

x1 = data1(:, 1);
x2 = data2(:, 1);
x3 = data3(:, 1);
y1 = data1(:, 2);
y2 = data2(:, 2);
y3 = data3(:, 2);

p1 = polyfit(x1, y1, 2);
p2 = polyfit(x2, y2, 2);
p3 = polyfit(x3, y3, 2);

X1 = linspace(min(x1), max(x1));
Y1 = polyval(p1, X1);
X2 = linspace(min(x2), max(x2));
Y2 = polyval(p2, X2);
X3 = linspace(min(x3), max(x3));
Y3 = polyval(p3, X3);

plot(X1, Y1, 'r', 'LineWidth', 2, X2, Y2, 'b', 'LineWidth', 2, X3, Y3, 'g', 'LineWidth', 2); 
legend('Mergesort', 'Quicksort', 'Heapsort');
hold off;
end
