#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <stdio.h>
MainScreenView::MainScreenView()
{

}

void MainScreenView::setupScreen()
{
    MainScreenViewBase::setupScreen();

}

void MainScreenView::tearDownScreen()
{
    MainScreenViewBase::tearDownScreen();
}


// UI 로직을 구현한다.
// Presenter로부터 데이터(Model의 값)을 전달받아 사용자에게 보여준다.
// 사용자와 상호작용을 담당하고, 이벤트를 Presenter에게 준다.
//void MainScreenView::controlBoxProgress(messageBuffer& msg){
//	printf("msg id : %d, %d %d %d\n",msg.mode, msg.adcConv[0], msg.adcConv[1], msg.adcConv[2]);
//}

void MainScreenView::updateADCGauge(uint16_t base, uint16_t inner, uint16_t outer){
	printf("JOYStickState %d %d %d\n", base, inner, outer);

	VR_BASE_boxProgress.setValue(base);
	VR_INNER_boxProgress.setValue(inner);
	VR_OUTER_boxProgress.setValue(outer);

	VR_BASE_boxProgress.invalidate();
	VR_INNER_boxProgress.invalidate();
	VR_OUTER_boxProgress.invalidate();
}

void MainScreenView::updateJOYGauge(uint16_t joyButton, uint16_t joyX, uint16_t joyY){
	printf("JOYStickState %d %d %d\n", joyButton, joyX, joyY);

	Joy_Button_flexButton.setPressed((uint8_t)joyButton);
	Joy_X_boxProgress.setValue(joyX);
	Joy_Y_boxProgress.setValue(joyY);

	Joy_Button_flexButton.invalidate();
	Joy_X_boxProgress.invalidate();
	Joy_Y_boxProgress.invalidate();
}

void MainScreenView::updateTextMessage(const char* textMsg){
	touchgfx::Unicode::strncpy(Message_textBoxBuffer, textMsg, MESSAGE_TEXTBOX_SIZE);
	Message_textBox.invalidate();
}
