using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnrealSharp;
using UnrealSharp.Attributes;
using UnrealSharp.CoreUObject;
using UnrealSharp.Engine;
using UnrealSharp.EnhancedInput;

namespace ManagedTeamProject.Character
{
    [UClass]
    public class APlayerCharacter : ABaseCharacter
    {
        [UProperty(PropertyFlags.EditAnywhere)] public UInputAction MoveAction { get; set; }

        [UProperty(PropertyFlags.EditAnywhere)] public UInputAction JumpAction { get; set; }

        [UProperty(PropertyFlags.EditAnywhere)] public TArray<UInputMappingContext> PlayerMappingContext { get; set; }

        protected override void BeginPlay()
        {
            base.BeginPlay();
            APlayerController? PlayerController = Controller as APlayerController;

            if (PlayerController != null) 
            {
                UEnhancedInputLocalPlayerSubsystem subsystem = GetLocalPlayerSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController);
                if (subsystem != null)
                {
                    int num = 0;
                    foreach (UInputMappingContext mappingContext in PlayerMappingContext)
                    {
                        subsystem.AddMappingContext(mappingContext, num);
                        num++;
                    }
                }
            }

            if (InputComponent != null)
            {
                UEnhancedInputComponent? EnInputComponent = InputComponent as UEnhancedInputComponent;
                if (EnInputComponent != null)
                {
                    EnInputComponent.BindAction(MoveAction, ETriggerEvent.Triggered, MoveFunc);
                    EnInputComponent.BindAction(JumpAction, ETriggerEvent.Started, JumpFunc);
                }
            }
        }

        public override void Tick(float deltaSeconds)
        {
            base.Tick(deltaSeconds);
        }

        [UFunction]
        public void MoveFunc(FInputActionValue value ,float _, float _2, UInputAction inputAction)
        {
            FVector2D vector2D = value.GetAxis2D();
            FRotator YawRotator = new FRotator(0.0f, Controller.ControlRotation.Yaw, 0.0f);
            FVector ForwardDirection = (YawRotator + new FRotator(0, 90, 0)).RotatorToVector();

            AddMovementInput(ForwardDirection, (float)vector2D.X);
        }

        [UFunction]
        public void JumpFunc(FInputActionValue value, float _, float _2, UInputAction inputAction)
        {

            Jump();
        }

    }
}
