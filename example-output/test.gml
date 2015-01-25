graph
[
hierarchic 1
label "MyGraph"
directed 1
node
[
id 1
label "foo"
]
node
[
id 2
label "3.14"
]
node
[
id 3
label "bar"
graphics
[
type "ellipse"
]
]
node
[
id 4
label "4"
]
edge
[
source 1
target 2
]
edge
[
source 1
target 3
]
edge
[
source 2
target 4
label "1.2"
graphics
[
targetArrow "standard"
style "dotted"
]
]
edge
[
source 3
target 4
label "baz"
graphics
[
targetArrow "standard"
style "dotted"
]
]
]
