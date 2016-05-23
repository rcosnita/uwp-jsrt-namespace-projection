debugger;
var comp1 = WindowsRuntimeComponent1.Class1.getInstance();

comp1.emitter.on("changedEvent", function(msg) {
	comp1.updateUI(msg);
});

comp1.emitter.on("changedEvent2", (msg) => {
	comp1.updateUI(msg);
});

let acceptsMessages = true;

while (acceptsMessages) {
	acceptsMessages = comp1.processEvents();
}