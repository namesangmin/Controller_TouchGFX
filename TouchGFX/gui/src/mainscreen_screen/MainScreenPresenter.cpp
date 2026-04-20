#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>


MainScreenPresenter::MainScreenPresenter(MainScreenView& v)
    : view(v)
{

}

void MainScreenPresenter::activate()
{

}

void MainScreenPresenter::deactivate()
{

}
// presenter는 model과 view의 중간 역할
// view로부터 이벤트를 전달받아 처리하고, model을 가공한다.
// model의 데이터를 view에 전달한다.
//
void ADCState::update(MainScreenView& v, messageBuffer& msg){
	v.updateADCGauge(msg.adcConv[0], msg.adcConv[1], msg.adcConv[2]);
	v.updateTextMessage(mode);
}
void JOYState::update(MainScreenView& v, messageBuffer& msg){
	v.updateJOYGauge(msg.adcConv[0], msg.adcConv[1], msg.adcConv[2]);
	v.updateTextMessage(mode);
}

void MainScreenPresenter::notifyOutputData(messageBuffer& msg){
	calculateRange(msg);
	choiceMode(msg);
}

void MainScreenPresenter::calculateRange(messageBuffer& msg){
	if(msg.mode == 0) msg.adcConv[0] = (msg.adcConv[0] * 100) / 4095;
	msg.adcConv[1] = (msg.adcConv[1] * 100) / 4095;
	msg.adcConv[2] = (msg.adcConv[2] * 100) / 4095;
}

void MainScreenPresenter::choiceMode(messageBuffer& msg){
	if(msg.mode==0) cState = &adcState;
	else if(msg.mode == 1) cState = &joyState;
	else{}

	cState->update(view, msg);
}
