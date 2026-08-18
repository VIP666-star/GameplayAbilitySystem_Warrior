// A Gas Demo

#pragma once

namespace Debug
{
	static void Print(const FString& Msg, const FColor& Color = FColor::Cyan, int32 Key = -1)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(Key, 5.f, Color, Msg);
			
			UE_LOG(LogTemp, Warning, TEXT("%s"), *Msg);
		}
	}
}
